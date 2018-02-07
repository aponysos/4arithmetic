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
  TRACE_FUNC();

  INFO_LOG() << "target: " << tgt_;
  INFO_LOG() << "operands: " << ops_;

  return false;
}
