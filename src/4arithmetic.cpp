// 4arithmetic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void InitLog()
{
  const char * PATTERN_STRING = "%d [%5p](%5t) %m%n";
  const char * LOG_FILE = "4arithmatic.log";
  const int LOG_PRIORITY = log4cpp::Priority::DEBUG;

  log4cpp::PatternLayout * layout = new log4cpp::PatternLayout();
  layout->setConversionPattern(PATTERN_STRING);

  log4cpp::Appender * appender = new log4cpp::FileAppender(
    "file", LOG_FILE);
  appender->setLayout(layout);

  log4cpp::Category & root = log4cpp::Category::getRoot();
  root.setPriority(LOG_PRIORITY);
  root.addAppender(appender);

  INFO_LOG() << "------------------------------------------------------------";
  INFO_LOG() << "4arithmatic program begin";
  INFO_LOG() << "log file: " << LOG_FILE << ", priority: " << LOG_PRIORITY;
  INFO_LOG() << "------------------------------------------------------------";
}

int str2int(const std::string & str)
{
  std::istringstream iss(str);
  int ret = 0;
  try {
    iss >> ret;
  }
  catch (std::exception & e) {
    ERROR_LOG() << e.what();
    throw;
  }
  return ret;
}

namespace log4cpp
{

template <class T>
std::ostream & operator<<(std::ostream & os, const std::vector<T> & vi)
{
  for (T i : vi)
    os << i << " ";
  return os;
}

}

bool compute(int result, const std::vector<int> & operands)
{
  INFO_LOG() << "result: " << result;
  INFO_LOG() << "operands: " << operands;
  return false;
}

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
  int result = str2int(*argv);

  // operands : other parameters
  std::vector<int> operands;
  for (; argc > 1; --argc, ++argv)
    operands.push_back(str2int(*argv));

  // compute
  if (compute(result, operands))
    INFO_LOG() << "compute ok";
  else
    INFO_LOG() << "compute failed";

  return 0;
}

