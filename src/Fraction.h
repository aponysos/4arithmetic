#pragma once

class Fraction
{
public:
  Fraction(int n = 0, int d = 1);
  Fraction(const Fraction & fr);

  Fraction & operator=(const Fraction & fr);

  std::string ToString() const;

private:
  void Reduce();
  static int GCD(int x, int y);

private:
  int nmr_; // numerator
  int dnm_; // denominator
};

std::ostream & operator<<(std::ostream & os, const Fraction & fr);

namespace log4cpp
{

  template <class T>
  std::ostream & operator<<(std::ostream & os, const std::vector<T> & vi)
  {
    for (T i : vi)
      os << i << " ";
    return os;
  }

}

bool compute(int result, const std::vector<int> & operands);
