// 只要把這段加在 class Solution 的外面（或是最上面）
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


// Using Hash Map
class MySolution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> ump;
        ump.reserve(nums.size());
        for (auto n : nums) {
            if (ump.find(n) != ump.end()) {
                return true;
            }
            ump[n] = true;
        }
        return false;
    }
};



// Using Set
#include <unordered_set>

class SubOptimalSolution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        us.reserve(nums.size());
        for (auto n : nums) {
            if (!us.insert(n).second) {
                return true;
            }
        }
        return false;
    }
};

// Using std::sort
// Note that this is just optimal in this case, not always optimal. (because this is O(NlogN))
class OptimalSolution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};
