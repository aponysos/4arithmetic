#include "stdafx.h"
#include "Util.h"
#include "Fraction.h"
#include "FourArithmeticProblem.h"

FourArithmeticProblem::FourArithmeticProblem(const Fraction & target, const std::vector<Fraction> & operands)
  : tgt_(target), ops_(operands)
{
}

FourArithmeticProblem::~FourArithmeticProblem()
{
}

bool FourArithmeticProblem::Resolve()
{
  return false;
}

bool compute(int result, const std::vector<int> & operands)
{
  TRACE_FUNC();

  INFO_LOG() << "result: " << result;
  INFO_LOG() << "operands: " << operands;

  Fraction f1(8, 2), f2(-9, 3), f3(4, -5);
  INFO_LOG() << f1;
  INFO_LOG() << f2;
  INFO_LOG() << f3;
  Fraction f4(2, 0);

  return false;
}
