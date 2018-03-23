#include "stdafx.h"
#include "Combination.h"

void Combination::Reset()
{
  flags_.clear();
  flags_.resize(n_);
  std::generate_n(flags_.begin(), m_, [] { return true; });
}

bool Combination::Next()
{
  auto i = std::adjacent_find(flags_.begin(), flags_.end(), 
    [](const bool &a, const bool &b) { return a && !b; });
  if (i == flags_.end())
    return false;
  std::swap(*i, *(i + 1));
  std::partition(flags_.begin(), i, [](const bool &a) { return a; });
  return true;
}
