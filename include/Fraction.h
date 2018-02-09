#pragma once

class Fraction
{
public:
  Fraction(int n = 0, int d = 1);
  Fraction(const Fraction & fr);
  Fraction & operator=(const Fraction & fr);
  Fraction(const std::string & str);

public:
  int GetNumerator() const { return nmr_; }
  int GetDenomitor() const { return dnm_; }

public:
  std::string ToString() const;
  Fraction & FromString(const std::string & str);

public:
  static int GCD(int x, int y);
  static int LCM(int x, int y);

private:
  void Reduce();
  static int GCD_i(int x, int y);
  static int LCM_i(int x, int y);

private:
  int nmr_; // numerator
  int dnm_; // denominator
};

std::ostream & operator<<(std::ostream & os, const Fraction & fr);
