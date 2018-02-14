#pragma once

class Expression
{
public:
  virtual ~Expression() {}
  virtual Fraction Evaluate() = 0;
  virtual Expression * Clone() const = 0;
};

class ValueExpression : public Expression
{
public:
  ValueExpression(Fraction val) : val_(val) {}
  ~ValueExpression() {}
  Fraction Evaluate() { return val_; }
  Expression * Clone() const { return new ValueExpression(val_); }

protected:
  Fraction val_;
};

class ArithmeticExpression : public Expression
{
public:
  ArithmeticExpression(Expression * lhs, Expression * rhs)
    : lhs_(lhs), rhs_(rhs) {}
  ArithmeticExpression(const ArithmeticExpression & ae);
  virtual ~ArithmeticExpression();
  virtual Fraction Evaluate();

protected:
  virtual Fraction DoEvaluate(Fraction lVal, Fraction rVal) = 0;

protected:
  Expression * lhs_;
  Expression * rhs_;
};

class PlusExpression : public ArithmeticExpression
{
public:
  PlusExpression(Expression * lhs, Expression * rhs)
    : ArithmeticExpression(lhs, rhs) {}
  virtual Expression * Clone() const { return new PlusExpression(lhs_->Clone(), rhs_->Clone()); }

protected:
  virtual Fraction DoEvaluate(Fraction lVal, Fraction rVal) { return lVal + rVal; }
};

class MinusExpression : public ArithmeticExpression
{
public:
  MinusExpression(Expression * lhs, Expression * rhs)
    : ArithmeticExpression(lhs, rhs) {}
  virtual Expression * Clone() const { return new MinusExpression(lhs_->Clone(), rhs_->Clone()); }

protected:
  virtual Fraction DoEvaluate(Fraction lVal, Fraction rVal) { return lVal - rVal; }
};

class MultipliesExpression : public ArithmeticExpression
{
public:
  MultipliesExpression(Expression * lhs, Expression * rhs)
    : ArithmeticExpression(lhs, rhs) {}
  virtual Expression * Clone() const { return new MultipliesExpression(lhs_->Clone(), rhs_->Clone()); }

protected:
  virtual Fraction DoEvaluate(Fraction lVal, Fraction rVal) { return lVal * rVal; }
};

class DividesExpression : public ArithmeticExpression
{
public:
  DividesExpression(Expression * lhs, Expression * rhs)
    : ArithmeticExpression(lhs, rhs) {}
  virtual Expression * Clone() const { return new DividesExpression(lhs_->Clone(), rhs_->Clone()); }

protected:
  virtual Fraction DoEvaluate(Fraction lVal, Fraction rVal) { return lVal / rVal; }
};

template<class T1, class T2>
inline Expression * MakePlusExpression(T1 lhs, T2 rhs)
{
  return new PlusExpression(
    new ValueExpression(Fraction(lhs)), new ValueExpression(Fraction(rhs)));
}

template<class T1, class T2>
inline Expression * MakeMinusExpression(T1 lhs, T2 rhs)
{
  return new MinusExpression(
    new ValueExpression(Fraction(lhs)), new ValueExpression(Fraction(rhs)));
}

template<class T1, class T2>
inline Expression * MakeMultipliesExpression(T1 lhs, T2 rhs)
{
  return new MultipliesExpression(
    new ValueExpression(Fraction(lhs)), new ValueExpression(Fraction(rhs)));
}

template<class T1, class T2>
inline Expression * MakeDividesExpression(T1 lhs, T2 rhs)
{
  return new DividesExpression(
    new ValueExpression(Fraction(lhs)), new ValueExpression(Fraction(rhs)));
}
