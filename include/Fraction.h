#ifndef FRACTION_H_INC
#define FRACTION_H_INC

class Fraction
{
public:
  // constructors
  Fraction(int n = 0, int d = 1);
  Fraction(const Fraction & fr);
  Fraction(const std::string & str);

  // assignment operator
  Fraction & operator=(const Fraction & fr);

public:
  // accessors
  int GetNumerator() const { return nmr_; }
  int GetDenominator() const { return dnm_; }

public:
  // stringlize
  std::string ToString() const;
  Fraction & FromString(const std::string & str);

public:
  // arithmetic methods
  Fraction AdditiveInverse() const;
  Fraction MultiplicativeInverse() const;
  Fraction & Plus(const Fraction & fr);
  Fraction & Multiply(const Fraction & fr);

public:
  // arithmetic operators
  Fraction operator-() { return AdditiveInverse(); }
  Fraction & operator+=(const Fraction & fr) { return Plus(fr); }
  Fraction & operator-=(const Fraction & fr) { return Plus(fr.AdditiveInverse()); }
  Fraction & operator*=(const Fraction & fr) { return Multiply(fr); }
  Fraction & operator/=(const Fraction & fr) { return Multiply(fr.MultiplicativeInverse()); }

  friend bool operator==(const Fraction & lhs, const Fraction & rhs);
  friend Fraction operator+(const Fraction & lhs, const Fraction & rhs);
  friend Fraction operator*(const Fraction & lhs, const Fraction & rhs);

public:
  // utils
  static int GCD(int x, int y);
  static int LCM(int x, int y);

private:
  static int GCD_i(int x, int y);
  static int LCM_i(int x, int y);
  void Reduce();

private:
  int nmr_; // numerator
  int dnm_; // denominator
};

bool operator==(const Fraction & lhs, const Fraction & rhs);
bool operator!=(const Fraction & lhs, const Fraction & rhs);
Fraction operator+(const Fraction & lhs, const Fraction & rhs);
Fraction operator-(const Fraction & lhs, const Fraction & rhs);
Fraction operator*(const Fraction & lhs, const Fraction & rhs);
Fraction operator/(const Fraction & lhs, const Fraction & rhs);
std::ostream & operator<<(std::ostream & os, const Fraction & fr);

#endif
