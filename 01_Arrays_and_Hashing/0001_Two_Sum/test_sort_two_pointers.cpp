#include <iostream>
#include <utility>
#include <vector>
#include "solution_sort_two_pointers.cpp"

struct TestCase {
    std::pair<std::vector<int>, int> input;
    std::vector<int> expected;
};

// AI-revised runner: validate lengths before comparing unordered indices.
bool sameIndices(const std::vector<int>& actual, const std::vector<int>& expected) {
    if (actual.size() != expected.size()) return false;
    if (actual == expected) return true;
    return actual.size() == 2 && actual[0] == expected[1] && actual[1] == expected[0];
}

int main() {
    if (!sameIndices({}, {}) || sameIndices({}, {0, 1}) ||
        sameIndices({0}, {0, 1}) || sameIndices({0, 0}, {0, 1}) ||
        sameIndices({0, 1}, {}) || !sameIndices({1, 0}, {0, 1})) return 1;

    std::vector<TestCase> testCases = {
        {{{2, 7, 11, 15}, 9}, {0, 1}},
        {{{3, 2, 4}, 6}, {1, 2}},
        {{{3, 3}, 6}, {0, 1}},
        {{{-3, 4, 3, 90}, 0}, {0, 2}},
        {{{0, -1, 12, -29, -12, 20, -10}, 10}, {5, 6}},
        {{{0, 0}, 0}, {0, 1}},
        {{{0, -2, 2}, 0}, {1, 2}},
        {{{2, 3, 1}, 6}, {}},
    };

    Solution solution;
    bool passed = true;
    for (std::size_t i = 0; i < testCases.size(); ++i) {
        auto& test = testCases[i];
        const auto actual = solution.twoSum(test.input.first, test.input.second);
        const bool correct = sameIndices(actual, test.expected);
        passed = passed && correct;
        std::cout << "Case " << i + 1 << ": " << (correct ? "Passed" : "Failed") << '\n';
    }
    return passed ? 0 : 1;
}
