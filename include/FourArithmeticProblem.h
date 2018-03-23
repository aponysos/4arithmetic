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
  const std::vector<Fraction> ops_;
  Expression * exp_;
};
