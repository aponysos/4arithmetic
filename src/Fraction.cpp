#include "stdafx.h"
#include "Util.h"
#include "Fraction.h"

Fraction::Fraction(int i, int d)
  : nmr_(i), dnm_(d)
{
  Reduce();
}

Fraction::Fraction(const Fraction & fr)
  : nmr_(fr.nmr_), dnm_(fr.dnm_)
{
}

Fraction::Fraction(const std::string & str)
  : Fraction(0, 1)
{
  FromString(str);
}

Fraction & Fraction::operator=(const Fraction & fr)
{
  nmr_ = fr.nmr_;
  dnm_ = fr.dnm_;
  return *this;
}

std::string Fraction::ToString() const
{
  std::ostringstream oss;
  if (dnm_ == 1)
    oss << nmr_;
  else
    oss << nmr_ << '|' << dnm_;

  return oss.str();
}

Fraction & Fraction::FromString(const std::string & str)
{
  auto iBar = str.find_first_of('|');
  if (std::string::npos == iBar) {
    // integer
    nmr_ = str2int(str);
    dnm_ = 1;
  }
  else {
    // fraction
    nmr_ = str2int(str.substr(0, iBar));
    dnm_ = str2int(str.substr(iBar + 1));
    Reduce();
  }
  return *this;
}

Fraction Fraction::AdditiveInverse() const
{
  return Fraction(-nmr_, dnm_);
}

Fraction Fraction::MultiplicativeInverse() const
{
  if (nmr_ == 0)
    throw std::exception("numerator is 0");
  
  return Fraction(dnm_, nmr_);
}

Fraction & Fraction::Plus(const Fraction & fr)
{
  nmr_ = nmr_ * fr.dnm_ + dnm_ * fr.nmr_;
  dnm_ *= fr.dnm_;

  Reduce();

  return *this;
}

Fraction & Fraction::Multiply(const Fraction & fr)
{
  nmr_ *= fr.nmr_;
  dnm_ *= fr.dnm_;

  Reduce();

  return *this;
}

int Fraction::GCD(int x, int y)
{
  if (x == 0 || y == 0)
    return 0;

  x = abs(x);
  y = abs(y);

  return GCD_i(x, y);
}

int Fraction::GCD_i(int x, int y)
{
  if (y == 0)
    return x;
  else if (x < y)
    return GCD_i(y, x);
  else
    return GCD_i(y, x%y);
}

int Fraction::LCM(int x, int y)
{
  if (x == 0 || y == 0)
    return 0;

  x = abs(x);
  y = abs(y);

  return LCM_i(x, y);
}

int Fraction::LCM_i(int x, int y)
{
  int gcd = GCD_i(x, y);
  return x * y / gcd;
}

void Fraction::Reduce()
{
  if (dnm_ == 0)
    throw std::exception("denomitor is 0");

  if (dnm_ < 0) {
    nmr_ = -nmr_;
    dnm_ = -dnm_;
  }

  int gcd = GCD(nmr_, dnm_);
  if (gcd > 1) {
    nmr_ /= gcd;
    dnm_ /= gcd;
  }
}

bool operator==(const Fraction & lhs, const Fraction & rhs)
{
  return lhs.nmr_ == rhs.nmr_ && lhs.dnm_ == rhs.dnm_;
}

bool operator!=(const Fraction & lhs, const Fraction & rhs)
{
  return !(lhs == rhs);
}

Fraction operator+(const Fraction & lhs, const Fraction & rhs)
{
  Fraction tmp(lhs); return tmp += rhs;
}

Fraction operator-(const Fraction & lhs, const Fraction & rhs)
{
  Fraction tmp(lhs); return tmp -= rhs;
}

Fraction operator*(const Fraction & lhs, const Fraction & rhs)
{
  Fraction tmp(lhs); return tmp *= rhs;
}

Fraction operator/(const Fraction & lhs, const Fraction & rhs)
{
  Fraction tmp(lhs); return tmp /= rhs;
}

std::ostream & operator<<(std::ostream & os, const Fraction & fr)
{
  os << fr.ToString();
  return os;
}
