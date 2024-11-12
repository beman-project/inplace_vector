<!--
SPDX-License-Identifier: <SPDX License Expression>
-->

# beman.inplace\_vector

A dynamically-resizable vector with fixed capacity and embedded storage

## Implements

- [`inplace_vector` P0843R14](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2024/p0843r14.html)

## Usage

### Definition in P0843

> `inplace_vector` is a dynamically-resizable array with capacity fixed 
at compile time and contiguous inplace storage, 
that is, the array elements are stored within the vector object itself. 
Its API closely resembles `std::vector<T, A>`, 
making it easy to teach and learn, 
and the inplace storage guarantee makes it useful in environments in 
which dynamic memory allocations are undesired.

### Code example

```cpp
// TODO: Add example
```

## How to Build

### Compiler support

Building this repository requires **C++20** or later.

### Dependencies

TODO: tested platforms.

### Instructions

<!-- TODO: add preset support -->

#### Manual CMake Build

```
# Configure build
$ cmake -S . -B build -DCMAKE_CXX_STANDARD=20
-- The CXX compiler identification is GNU 11.4.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.4s)
-- Generating done (0.0s)
-- Build files have been written to: /.../inplace_vector/build

# Build
$ cmake --build build
[ 50%] Building CXX object src/beman/inplace_vector/tests/CMakeFiles/beman.inplace_vector.test.dir/inplace_vector.test.cpp.o
[100%] Linking CXX executable beman.inplace_vector.test
[100%] Built target beman.inplace_vector.test

# Run tests
$ ctest --test-dir build/
Internal ctest changing into directory: /.../inplace_vector/build
Test project /.../inplace_vector/build
    Start 1: beman.inplace_vector.test
1/1 Test #1: beman.inplace_vector.test ........   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.01 sec
```

