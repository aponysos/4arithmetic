// 4arithmetic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Util.h"
#include "Fraction.h"
#include "Expression.h"
#include "FourArithmeticProblem.h"

using namespace std;

int main(int argc, char ** argv)
{
  InitLog();

  // ignore first parameter
  --argc;
  ++argv;

  // check # of parameters
  INFO_LOG() << "argc = " << argc;
  if (argc < 2) {
    WARN_LOG() << "not enough parameters";
    return 0;
  }

  // result: first parameter
  Fraction target = str2int(*argv++);
  --argc;

  // operands : other parameters
  std::vector<Fraction> operands;
  for (; argc > 0; --argc, ++argv)
    operands.push_back(Fraction(str2int(*argv)));

  // compute
  try {
    FourArithmeticProblem fap(target, operands);
    if (fap.Resolve())
      INFO_LOG() << "resolvable";
    else
      INFO_LOG() << "unresolvable";
  }
  catch (std::exception & e) {
    ERROR_LOG() << e.what();
    throw;
  }

  return 0;
}
