#include <beman/inplace_vector/inplace_vector.hpp>
#include <functional>
#include <type_traits>

using namespace beman::inplace_vector;

#define S_ASSERT(EXP)                                                          \
  do {                                                                         \
    if (!(EXP)) {                                                              \
      return false;                                                            \
    }                                                                          \
  } while (0)

struct NonTrivial {
  int z = 0;
};
static_assert(!std::is_trivial_v<NonTrivial>);

static_assert(std::invoke([]() {
                inplace_vector<int, 0> vec;

                // sizes
                S_ASSERT(vec.max_size() == 0);
                S_ASSERT(vec.capacity() == 0);
                S_ASSERT(vec.size() == 0);
                S_ASSERT(vec.empty());

                // itr
                S_ASSERT(vec.begin() == vec.end());
                S_ASSERT(vec.cbegin() == vec.cend());
                S_ASSERT(vec.rbegin() == vec.rend());
                S_ASSERT(vec.crbegin() == vec.crend());

                // push_back
                S_ASSERT(vec.try_push_back(0) == nullptr);
                S_ASSERT(vec.try_emplace_back(0) == nullptr);

                return true;
              }),
              "Should be constexpr for all 0 capacity for trivial type");

static_assert(std::invoke([]() {
                inplace_vector<NonTrivial, 0> vec;

                // sizes
                S_ASSERT(vec.max_size() == 0);
                S_ASSERT(vec.capacity() == 0);
                S_ASSERT(vec.size() == 0);
                S_ASSERT(vec.empty());

                // itr
                S_ASSERT(vec.begin() == vec.end());
                S_ASSERT(vec.cbegin() == vec.cend());
                S_ASSERT(vec.rbegin() == vec.rend());
                S_ASSERT(vec.crbegin() == vec.crend());

                S_ASSERT(vec.try_push_back({}) == nullptr);

                return true;
              }),
              "Should be constexpr for all 0 capacity for non-trivial type");

static_assert(std::invoke([]() {
                // sizes
                {
                  inplace_vector<int, 1> vec;
                  vec.push_back(1);

                  S_ASSERT(vec.max_size() == 1);
                  S_ASSERT(vec.capacity() == 1);
                  S_ASSERT(vec.size() == 1);
                  S_ASSERT(!vec.empty());
                }

                // Access
                {

                  inplace_vector<int, 1> vec;
                  vec.push_back(1);

                  S_ASSERT(vec[0] == 1);
                  S_ASSERT(vec.front() == 1);
                  S_ASSERT(vec.back() == 1);
                }

                // forward itr
                {
                  inplace_vector<int, 1> vec;
                  vec.push_back(1);

                  auto itr = vec.begin();
                  S_ASSERT(*itr == 1);
                  itr += 1;
                  S_ASSERT(itr == vec.end());
                }

                // backward itr
                {
                  inplace_vector<int, 1> vec;
                  vec.push_back(1);

                  auto itr = vec.rbegin();
                  S_ASSERT(*itr == 1);
                  itr += 1;
                  S_ASSERT(itr == vec.rend());
                }

                // try variant
                {
                  inplace_vector<int, 1> vec;
                  S_ASSERT(*vec.try_push_back(1) == 1);
                  S_ASSERT(vec.try_push_back(2) == nullptr);
                }

                return true;
              }),
              "Single push_back");

static_assert(std::invoke([]() {
                // push pop back
                {
                  inplace_vector<int, 5> vec;
                  vec.push_back(1);
                  vec.pop_back();

                  S_ASSERT(vec.empty());
                }

                // resize
                {
                  inplace_vector<int, 5> vec;
                  vec.push_back(1);
                  vec.push_back(2);

                  S_ASSERT(vec.size() == 2);

                  vec.resize(1);
                  S_ASSERT(vec.size() == 1);
                  S_ASSERT(vec.back() == 1);
                }

                return true;
              }),
              "Single push_back");

int main() {
  // compile means pass
}
