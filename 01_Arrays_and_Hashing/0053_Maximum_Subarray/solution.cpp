#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const static int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// My first thought using prefix sum.
class MySolution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prefixSum(nums.size()+1, 0);
        int mini = 0;
        int max_sum = INT_MIN;
        for(int i = 1; i <= nums.size(); ++i) {
            prefixSum[i] = nums[i-1] + prefixSum[i-1];
            if(prefixSum[i] - mini > max_sum)
                max_sum = prefixSum[i] - mini;
            if(prefixSum[i] < mini)
                mini = prefixSum[i];
        }
        return max_sum;
    }
};

class BetterSolution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int max_sum = INT_MIN;

        // 我們直接走訪陣列，不需要額外的 vector
        for (int p : nums) {
            // 核心邏輯 (狀態轉移)：
            // 如果我把過去累積的 current_sum 加上現在這個數字 p，
            // 發現還不如「直接從 p 自己重新開始算」來得大，
            // 那我就果斷拋棄過去的累積，從 p 開始新的子陣列！
            current_sum = max(p, current_sum + p);

            // 隨時記錄我們看過的歷史最高區間和
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};