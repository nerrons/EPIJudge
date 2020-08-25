#pragma once
#include <iostream>
#include <vector>
#include <iterator>

/**
 * Simple helper function that prints a vector
 * @tparam T The value type of the vector
 * @param v The vector to be printed
 */
template<typename T>
void print_vector(const std::vector<T>& v) {
  std::cout << "{ ";
  std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, ", "));
  std::cout << '}' << std::endl;
}
