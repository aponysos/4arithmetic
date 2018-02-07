#pragma once

class FourArithmeticProblem
{
public:
  FourArithmeticProblem(const Fraction & target, const std::vector<Fraction> & operands);
  ~FourArithmeticProblem();

public:
  bool Resolve();

private:
  Fraction tgt_;
  std::vector<Fraction> ops_;
};

class Expression
{

};
