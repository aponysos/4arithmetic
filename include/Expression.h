#pragma once

class Expression
{
public:
  Expression(Expression * lhs, Expression * rhs, Fraction val)
    : lhs_(lhs), rhs_(rhs), val_(val) {}
  virtual ~Expression() {}
  virtual Fraction Evaluate() = 0;

protected:
  Expression * lhs_;
  Expression * rhs_;
  Fraction val_;
};

class ValueExpression : public Expression
{
public:
  ValueExpression(Fraction val) : Expression(nullptr, nullptr, val) {}
  ~ValueExpression() {}
  Fraction Evaluate() { return val_; }
};

template<class T>
class ArithmeticExpression : public Expression
{
public:
  ArithmeticExpression(Expression * lhs, Expression * rhs)
    : Expression(lhs, rhs, 0) {}
  ~ArithmeticExpression();
  Fraction Evaluate();

private:
  T func_;
};

template<class T>
ArithmeticExpression<T>::~ArithmeticExpression()
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

template<class T>
Fraction ArithmeticExpression<T>::Evaluate()
{
  if (lhs_ == nullptr || rhs_ == nullptr)
    throw std::exception("invalid expression");

  Fraction lVal = lhs_->Evaluate();
  Fraction rVal = rhs_->Evaluate();

  return val_ = func_(lVal, rVal);
}

typedef ArithmeticExpression<std::plus<Fraction>> PlusExpression;
typedef ArithmeticExpression<std::minus<Fraction>> MinusExpression;
typedef ArithmeticExpression<std::multiplies<Fraction>> MultipliesExpression;
typedef ArithmeticExpression<std::divides<Fraction>> DividesExpression;
