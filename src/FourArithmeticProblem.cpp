#include "stdafx.h"
#include "Util.h"
#include "Fraction.h"
#include "Expression.h"
#include "Combination.h"
#include "FourArithmeticProblem.h"

FourArithmeticProblem::FourArithmeticProblem(const Fraction & target, const std::vector<Fraction> & operands)
  : tgt_(target), ops_(operands), exp_(nullptr)
{
}

FourArithmeticProblem::~FourArithmeticProblem()
{
  delete exp_;
  exp_ = nullptr;
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

const std::string EXP_STRING[] = {
  "Plus",
  "Minus",
  "Multiplies",
  "Divides",
  "RMinus",
  "RDivides",
  "None",
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

using AOP = std::function<Fraction(const Fraction &, const Fraction &)>;
AOP aops[] = {
  [](const Fraction & lhs, const Fraction & rhs) { return lhs + rhs; }, 
  [](const Fraction & lhs, const Fraction & rhs) { return lhs - rhs; },
  [](const Fraction & lhs, const Fraction & rhs) { return lhs * rhs; },
  [](const Fraction & lhs, const Fraction & rhs) { return lhs / rhs; },
  [](const Fraction & lhs, const Fraction & rhs) { return rhs - lhs; },
  [](const Fraction & lhs, const Fraction & rhs) { return rhs / lhs; },
};

template<class T1, class T2>
Fraction RunFractionArithmetic(T1 lhs, T2 rhs, AOP aop)
{
  return aop(Fraction(lhs), Fraction(rhs));
}

bool FourArithmeticProblem::Resolve()
{
  TRACE_FUNC();
  INFO_LOG() << ops_.size() << " (" << ops_ << ")" << " -> " << tgt_;

  if (ops_.size() < 2) {
    throw std::exception("");
  }
  else if (ops_.size() == 2) {
    for (int t = 0; t < None; ++t) {
      try {
        Fraction res = RunFractionArithmetic(ops_[0], ops_[1], aops[t]);
        if (res == tgt_) {
          //exp_ = e;
          return true;
        }
      }
      catch (std::exception & e) {
        WARN_LOG() << "exception : " << e.what() << " igored";
      }
    }
  }
  else {
    Combination c(ops_.size(), 2);
    c.Reset();
    do {
      auto f = c.Current();
      std::vector<Fraction> selectedOps, remainedOps;
      for (size_t i = 0; i < ops_.size(); ++i) {
        if (f[i])
          selectedOps.push_back(ops_[i]);
        else
          remainedOps.push_back(ops_[i]);
      }

      for (size_t t = 0; t < None; ++t) {
        std::vector<Fraction> newOps{ remainedOps };
        try {
          DEBUG_LOG() << EXP_STRING[t] << selectedOps[0] << " " << selectedOps[1];
          Fraction res = RunFractionArithmetic(selectedOps[0], selectedOps[1], aops[t]);
          newOps.push_back(res);
        }
        catch (std::exception & e) {
          WARN_LOG() << "exception igored: " << e.what();
          continue;
        }
        FourArithmeticProblem newProblem(tgt_, newOps);
        if (newProblem.Resolve()) {
          INFO_LOG() << "resolvable: " << tgt_ << " <- (" << ops_ << ")";
          return true;
        }
        else
          newOps.pop_back();
      }
     } while (c.Next());
  }

  DEBUG_LOG() << "unresolvable: " << tgt_ << " <- (" << ops_ << ")";
  return false;
}
