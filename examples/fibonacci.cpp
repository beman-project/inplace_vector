#include <beman/inplace_vector/inplace_vector.hpp>
#include <cassert>
#include <iostream>

using namespace beman::inplace_vector;

/**
 * Generates fibonacci sequence using inplace_vector.
 * See: https://en.wikipedia.org/wiki/Fibonacci_sequence
 */
template <int Capacity> inplace_vector<int, Capacity> fibonacci_to(int num) {
  assert(num < Capacity);

  inplace_vector<int, Capacity> vec;

  vec.push_back(0);
  vec.push_back(1);

  for (auto i = 2; i <= num; ++i) {
    auto new_val = vec[i - 1] + vec[i - 2];
    vec.push_back(new_val);
  }

  return vec;
}

/**
 * Expected program output:
 *
 * 0: 0
 * 1: 1
 * 2: 1
 * 3: 2
 * 4: 3
 * 5: 5
 * 6: 8
 * 7: 13
 * 8: 21
 * 9: 34
 * 10: 55
 *
 */
int main() {
  auto fib_seq = fibonacci_to<50>(10);
  for (auto i = 0u; i < fib_seq.size(); ++i)
    std::cout << i << ": " << fib_seq[i] << "\n";
  std::cout << std::endl;
}
