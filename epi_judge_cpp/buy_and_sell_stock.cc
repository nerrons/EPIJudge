#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  auto lowest_so_far = std::numeric_limits<double>::infinity();
  auto max_profit = 0.0;
  for (const auto p : prices) {
    max_profit = std::max(p - lowest_so_far, max_profit);
    lowest_so_far = std::min(p, lowest_so_far);
  }
  return max_profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
