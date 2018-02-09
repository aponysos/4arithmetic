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

Fraction & Fraction::operator=(const Fraction & fr)
{
  nmr_ = fr.nmr_;
  dnm_ = fr.dnm_;
  return *this;
}

Fraction::Fraction(const std::string & str)
  : Fraction(0, 1)
{
  FromString(str);
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

void Fraction::Reduce()
{
  if (dnm_ == 0)
    throw std::exception("divided by 0");

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

std::ostream & operator<<(std::ostream & os, const Fraction & fr)
{
  os << fr.ToString();
  return os;
}
