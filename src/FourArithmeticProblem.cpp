#include "stdafx.h"
#include "Util.h"
#include "Fraction.h"
#include "Expression.h"
#include "FourArithmeticProblem.h"

FourArithmeticProblem::FourArithmeticProblem(const Fraction & target, const std::vector<Fraction> & operands)
  : tgt_(target), ops_(operands), exp_(nullptr)
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

  if (ops_.size() == 2) {

  }

  return false;
}
