#include "stdafx.h"
#include "Fraction.h"
#include "Expression.h"

ArithmeticExpression::ArithmeticExpression(const ArithmeticExpression & ae)
  : lhs_(ae.lhs_->Clone()), rhs_(ae.rhs_->Clone())
{
}

ArithmeticExpression::~ArithmeticExpression()
{
  if (lhs_ != nullptr) {
    delete lhs_;
    lhs_ = nullptr;
  }
  if (rhs_ != nullptr) {
    delete rhs_;
    rhs_ = nullptr;
  }
}

Fraction ArithmeticExpression::Evaluate()
{
  if (lhs_ == nullptr || rhs_ == nullptr)
    throw std::logic_error("invalid expression");

  Fraction lVal = lhs_->Evaluate();
  Fraction rVal = rhs_->Evaluate();

  return DoEvaluate(lVal, rVal);
}
