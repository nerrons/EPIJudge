#include <string>
#include <algorithm>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
using std::string;

string IntToString(int x) {
  if (x == 0) {
    return "0";
  }

  std::string s;
  auto negative = x < 0;
  //  x = std::abs(x); Not good, because if x is the most negative number this will overflow
  while (x) {
    auto digit = std::abs(x % 10);
    s.push_back('0' + digit);
    x /= 10;
  }
  if (negative) {
    s.push_back('-');
  }
  std::reverse(s.begin(), s.end());
  return s;
}
int StringToInt(const string& s) {
  auto res = 0;
  auto sign = s[0] == '-' ? -1 : 1;
  auto it = s.begin();
  while (*it == '-' || *it == '+' || *it == '0') {
    ++it;
  }
  while (it != s.end()) {
    res = res * 10 + (*it - '0');
    ++it;
  }
  return sign * res;
}

void Wrapper(int x, const string& s) {
  if (stoi(IntToString(x)) != x) {
    throw TestFailure("Int to string conversion failed");
  }

  if (StringToInt(s) != x) {
    throw TestFailure("String to int conversion failed");
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "s"};
  return GenericTestMain(args, "string_integer_interconversion.cc",
                         "string_integer_interconversion.tsv", &Wrapper,
                         DefaultComparator{}, param_names);
}
