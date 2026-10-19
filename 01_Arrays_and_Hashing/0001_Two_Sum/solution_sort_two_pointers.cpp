#pragma once
#include <vector>
#include <utility>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> sorted;
        sorted.reserve(nums.size());
        for (int k = 0; k < (int)nums.size(); ++k) sorted.push_back({nums[k], k});
        std::sort(sorted.begin(), sorted.end());
        int i = 0, j = (int)sorted.size() - 1;
        while(i < j) {
            int sum = sorted[i].first + sorted[j].first;
            if (sum == target) return {sorted[i].second, sorted[j].second};
            else if (sum < target) ++i;
            else --j;
        }
        return {};
    }
};
