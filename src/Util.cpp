#include "stdafx.h"
#include "Util.h"

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
