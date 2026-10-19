#include "solution.h"
#include <utility>
#include <iostream>
#include <vector>

using namespace std;

struct TestCase {
    pair<vector<int>, int> input;
    int expected;
};

int main() {
    vector<TestCase> testCases = {
        // Default testcases.
        {{{-1,0,3,5,9,12}, 9}, 4},
        {{{-1,0,3,5,9,12}, 2}, -1},

        // My testcases
        {{{1}, 1}, 0},
        {{{1}, 0}, -1},
        {{{1, 2, 3, 4}, 1}, 0}, 
        {{{1, 2, 3, 4}, 4}, 3}, 
    };

    Solution inst_sol;

    bool AC = true;
    for (auto testCase : testCases) {
        pair<vector<int>, int> input_snap = testCase.input;
        int result = inst_sol.search(testCase.input.first, testCase.input.second);
        bool correct = result == testCase.expected && input_snap == testCase.input; 
        if(correct == false) {
            AC = false;
            cout << "Failed!" << " Result is " << result << " but expected " << testCase.expected << endl;
        }
        else {
            cout << "Passed!" << endl;
        }
    }

    return (int)!AC;
}