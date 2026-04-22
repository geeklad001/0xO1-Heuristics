#include <vector>
#include <unordered_map>

using namespace std;

class Naive_Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums.size(); ++j) {
                if(i != j) {
                    if(nums[i] + nums[j] == target) {
                        solution.push_back(i);
                        solution.push_back(j);
                        return solution;
                    }
                }
            }
        }
        return solution;
    }
};

class Naive_Solution_Better {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i+1; j < nums.size(); ++j) {
                if(nums[i] + nums[j] == target) {
                    solution.push_back(i);
                    solution.push_back(j);
                    return solution;
                }
            }
        }
        return solution;
    }
};

// Faster using unordered_map (Hash map)
class Faster_Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        for(int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (ump.find(complement) != ump.end()) {
                return {ump[complement], i};
            }
            ump[nums[i]] = i;
        }
        return {};
    }
};

// Reserve capacity for hash map to achieve better run time.
class Optimal_Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        ump.reserve(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (ump.find(complement) != ump.end()) {
                return {ump[complement], i};
            }
            ump[nums[i]] = i;
        }
        return {};
    }
};