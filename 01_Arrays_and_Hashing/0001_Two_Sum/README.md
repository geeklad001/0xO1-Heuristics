# 0001 Two Sum

[Official problem](https://leetcode.com/problems/two-sum/)

## Versions

| Version | Implementation | Time | Auxiliary space |
| --- | --- | --- | --- |
| Existing archive | [Brute force and hash map](solution.cpp) | Brute force: O(N^2); hash map: average O(N), worst O(N^2) | Brute force: O(1); hash map: O(N) |
| 2026-10-18 practice | [Sorting + two pointers](solution_sort_two_pointers.cpp) | O(N log N) | O(N) |

Historical implementations are an archive, not a claim of current recall.

## Sorting + two pointers

Store `(value, original_index)` pairs, then sort them. Search with left and right
pointers; return the original indices. The condition `left < right` prevents
reusing an element, including when two elements have the same value.

If the endpoint sum exceeds the target, any other value in the current range
paired with the right endpoint produces a sum at least as large. That endpoint
can be discarded. The symmetric argument applies to the left endpoint when the
sum is too small. Negative values do not change these ordering arguments.

Building pairs costs O(N), sorting O(N log N), and scanning O(N); auxiliary
space is O(N). Already-sorted input can be searched in O(N) time and O(1) space.
The already-sorted variation was explained verbally, not implemented.

## Local tests

Eight cases cover the three statement examples, negative values, reordered
original indices, repeated zeros, a single zero that cannot be reused, and a
custom no-match case. Returning an empty vector for no match is extra behavior,
outside the problem's guaranteed-solution input. Either index order is accepted.
These visible cases do not establish exhaustive correctness.

On 2026-10-19, the agent compiled the public runner with GCC 11.4.0 and the
command below, then executed it: all eight cases passed, exit code 0. The
comparison helper's empty/malformed-result checks also passed. This verifies
the publication version; it does not retroactively change the original practice
evidence or establish an independent assessment pass.

Run from this directory:

```sh
g++ -std=c++17 -O2 -Wall -Wextra -Wpedantic test_sort_two_pointers.cpp -o /tmp/two-sum-tests
/tmp/two-sum-tests
```

## Practice and assistance

- Practice date: 2026-10-18; publication draft: 2026-10-19.
- The learner reported completing the sorting solution before the discussion.
  The published solution preserves its bytes apart from a final newline.
- AI assistance covered reasoning questions, edge-case suggestions, hash map
  strategy, and complexity/benchmark explanations. This note is AI-written from
  that discussion. Whether prior answers were consulted is unknown.
- The public test runner is AI-revised from the learner's eight cases: it checks
  result lengths before indexing and checks the comparison helper. Private
  practice files are preserved separately.
- The learner reported tests passing and a manual LeetCode submission. The
  platform verdict was not provided; Accepted is not asserted.
- This was guided practice, not an independent assessment.
- Earlier LeetCode runtime comparisons favored sorting according to the learner.
  No controlled local benchmark was run; 0 ms does not establish a universal
  performance advantage.
