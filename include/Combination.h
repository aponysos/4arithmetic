#ifndef COMBINATION_H_INC
#define COMBINATION_H_INC

class Combination
{
public:
  Combination(int n, int m) : n_(n), m_(m), flags_(n) {}

public:
  std::vector<bool> Reset();
  std::vector<bool> Current() { return flags_; }
  bool Next();

private:
  int n_;
  int m_;
  std::vector<bool> flags_;
};

#endif
