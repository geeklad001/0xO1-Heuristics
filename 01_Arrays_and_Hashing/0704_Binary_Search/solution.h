#pragma once
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int result = -1;
        int right = (int)nums.size() - 1;
        int left = 0;
        while (left >= 0 && right < (int)nums.size() && right >= left) {
            int mid = (right+left)/2;
            if (nums[mid] == target) {
                result = mid;
                break;
            }
            else if (nums[mid] > target) right = mid-1;
            else left = mid+1;
        }
        return result;
    }
};