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

enum ExpressionType
{
  Plus, 
  Minus, 
  Multiplies, 
  Divides, 
  RMinus, 
  RDivides,
  None, 
};

const ExpressionType EXP_TYPES[] = {
  Plus,
  Minus,
  Multiplies,
  Divides,
  RMinus,
  RDivides,
  None,
};

template<class T1, class T2>
inline Expression * MakeExpression(ExpressionType tp, T1 lhs, T2 rhs)
{
  switch (tp) {
  case Plus:
    return MakePlusExpression(lhs, rhs);
  case Minus:
    return MakeMinusExpression(lhs, rhs);
  case Multiplies:
    return MakeMultipliesExpression(lhs, rhs);
  case Divides:
    return MakeDividesExpression(lhs, rhs);
  case RMinus:
    return MakeMinusExpression(rhs, lhs);
  case RDivides:
    return MakeDividesExpression(rhs, lhs);
  default:
    throw std::exception("unknown ExpressionType");
  }
}

bool FourArithmeticProblem::Resolve()
{
  TRACE_FUNC();

  INFO_LOG() << "target: " << tgt_;
  INFO_LOG() << "operands: " << ops_;

  delete exp_;
  exp_ = nullptr;

  if (ops_.size() < 2) {
    throw std::exception("");
  }
  else if (ops_.size() == 2) {
    for (int t = 0; t < None; ++t) {
      Expression * e = MakeExpression(EXP_TYPES[t], ops_[0], ops_[1]);
      Fraction res = e->Evaluate();
      if (res == tgt_) {
        exp_ = e;
        return true;
      }
    }
  }
  else {
    
  }

  return false;
}
