# better_assert

[![Build Status](https://travis-ci.org/amallia/better_assert.svg?branch=master)](https://travis-ci.org/amallia/better_assert)

A better assertion library which also prints a message.

## Usage

```cpp
// example.cpp
#include "better_assert/better_assert.hpp"

better_assert(1 != 1, "1 is always equal to 1.");

// Output
// [example.cpp:2] Assertion `1 != 1` failed.
// 1 is always equal to 1.
```

