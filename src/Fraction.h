#pragma once

class Fraction
{
public:
  Fraction(int n = 0, int d = 1);
  Fraction(const Fraction & fr);

  Fraction & operator=(const Fraction & fr);

  std::string ToString() const;

public:

private:
  void Reduce();
  static int GCD(int x, int y);

private:
  int nmr_; // numerator
  int dnm_; // denominator
};

std::ostream & operator<<(std::ostream & os, const Fraction & fr);

bool compute(int result, const std::vector<int> & operands);
