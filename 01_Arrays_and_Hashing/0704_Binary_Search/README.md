# 0704 Binary Search

[Official problem](https://leetcode.com/problems/binary-search/)

- [Solution](solution.h)
- [Local tests](test.cpp)

## Approach

Search the sorted input using an inclusive interval `[left, right]`. If the
middle element matches the target, return its index. Otherwise discard the
middle element and the half that cannot contain the target. Return `-1` if the
interval becomes empty.

Time complexity is O(log N), and auxiliary space is O(1). The implementation
does not modify the input. It uses integer indices and `(left + right) / 2`;
the sum must fit in `int`. For reuse with larger index ranges, an overflow-safe
midpoint calculation would need a separate revision.

## Verification

On 2026-10-19, the agent compiled and ran the published tests with GCC 11.4.0:
all six cases passed, exit code 0. Tests cover a found target, a missing target,
singleton hit/miss, and both endpoints. Each case also checks that the input is
unchanged. These are visible local tests, not exhaustive or hidden-test coverage.

Run from this directory:

```sh
g++ -std=c++17 -O2 -Wall -Wextra -Wpedantic test.cpp -o /tmp/binary-search-tests
/tmp/binary-search-tests
```

## Provenance

The learner selected these existing practice files for publication. Both code
and tests are copied byte-for-byte; the agent wrote this note and updated the
repository index. Original practice date, historical assistance, prior answer
exposure, and platform verdict were not confirmed. Publication and local test
verification do not establish an independent assessment pass.
