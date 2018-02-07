#pragma once

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

int str2int(const std::string & str);

void InitLog();
