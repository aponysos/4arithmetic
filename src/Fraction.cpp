#include "stdafx.h"
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

std::string Fraction::ToString() const
{
  std::ostringstream oss;
  if (dnm_ == 1)
    oss << nmr_;
  else
    oss << nmr_ << '|' << dnm_;

  return oss.str();
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
  x = abs(x);
  y = abs(y);

  if (y == 0)
    return x;
  else if (x < y)
    return GCD(y, x);
  else
    return GCD(y, x%y);
}

std::ostream & operator<<(std::ostream & os, const Fraction & fr)
{
  os << fr.ToString();
  return os;
}
