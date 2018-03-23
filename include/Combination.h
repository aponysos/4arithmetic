#pragma once

class Combination
{
public:
  Combination(int n, int m) : n_(n), m_(m), flags_(n) {}

public:
  void Reset();
  std::vector<bool> Current() { return flags_; }
  bool Next();

private:
  int n_;
  int m_;
  std::vector<bool> flags_;
};