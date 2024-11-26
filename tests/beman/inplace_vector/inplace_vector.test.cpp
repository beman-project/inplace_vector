// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include <beman/inplace_vector/inplace_vector.hpp>
#include <type_traits>

using namespace beman::inplace_vector;

struct NonTrivial {
  int z = 5;

  bool operator==(NonTrivial const &other) const { return this->z == other.z; }
};
static_assert(!std::is_trivial_v<NonTrivial>);

template <typename T> constexpr void test() {
  using vec = inplace_vector<T, 42>;
  vec range{T(1), T(1337), T(42), T(12), T(0), T(-1)};
  const vec const_range{T(0), T(42), T(1337), T(42), T(5), T(-42)};

  auto &&bracket = range[3];
  static_assert(std::is_same<decltype(bracket), typename vec::reference>::value,
                "");
  assert(bracket == T(12));

  range[3] = T(4);
  auto &&bracket_assign = range[3];
  static_assert(
      std::is_same<decltype(bracket_assign), typename vec::reference>::value,
      "");
  assert(bracket_assign == T(4));

  // Continue with const reference.
  auto &&const_bracket = const_range[3];
  static_assert(std::is_same<decltype(const_bracket),
                             typename vec::const_reference>::value,
                "");
  assert(const_bracket == T(42));

  auto &&front = range.front();
  static_assert(std::is_same<decltype(const_bracket),
                             typename vec::const_reference>::value,
                "");
  assert(front = T(1));

  auto &&const_front = const_range.front();
  static_assert(
      std::is_same<decltype(const_front), typename vec::const_reference>::value,
      "");
  assert(const_front == T(0));

  auto &&back = range.back();
  static_assert(std::is_same<decltype(back), typename vec::reference>::value,
                "");
  assert(back == T(-1));

  auto &&const_back = const_range.back();
  static_assert(
      std::is_same<decltype(const_back), typename vec::const_reference>::value,
      "");
  assert(const_back == -42);

  auto data = range.data();
  static_assert(std::is_same<decltype(data), typename vec::pointer>::value, "");
  assert(*data == T(1));
  assert(data == std::addressof(front));

  auto const_data = const_range.data();
  static_assert(
      std::is_same<decltype(const_data), typename vec::const_pointer>::value,
      "");
  assert(*const_data == T(0));
  assert(const_data == std::addressof(const_front));
}

void test_exceptions() {
  using vec = inplace_vector<int, 42>;
  {
    try {
      vec too_small{};
      auto res = too_small.at(5);
    } catch (const std::out_of_range &) {
    } catch (...) {
      assert(false);
    }
    try {
      const vec too_small{};
      auto res = too_small.at(5);
    } catch (const std::out_of_range &) {
    } catch (...) {
      assert(false);
    }
  }
}

template <typename T> void test_const() {
  inplace_vector<const T, 20> vec;
  vec.push_back({50});
  const T &first = vec.front();
  assert(first == T{50});
}

int main() {
  test<int>();
  test_exceptions();

  test_const<int>();
  test_const<NonTrivial>();
  return 0;
}
