#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// My first thought: build a nagative minimum and a maximum prefix and postfix product.
class MySolution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> prefixPositive(nums.size()), prefixNegative(nums.size());

        int max_product;
        prefixPositive[0] = prefixNegative[0] = max_product = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            int temp_positive_product = nums[i] * prefixPositive[i-1];
            int temp_negative_product = nums[i] * prefixNegative[i-1];
            
            if (temp_positive_product > max_product)
                max_product = temp_positive_product;
            if (temp_negative_product > max_product)
                max_product = temp_negative_product;
            if (nums[i] > max_product)
                max_product = nums[i];

            prefixPositive[i] = nums[i];
            if (temp_positive_product > prefixPositive[i])
                prefixPositive[i] = temp_positive_product;
            if (temp_negative_product > prefixPositive[i])
                prefixPositive[i] = temp_negative_product;

            prefixNegative[i] = nums[i];
            if (temp_positive_product < prefixNegative[i])
                prefixNegative[i] = temp_positive_product;
            if (temp_negative_product < prefixNegative[i])
                prefixNegative[i] = temp_negative_product;
        }
        return max_product;
    }
};

// Better solution by AI.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 防禦性編程：處理空陣列
        if (nums.empty()) return 0;

        // 我們不需要 O(N) 的陣列，只需要三個 O(1) 變數：
        // 1. max_so_far: 走到目前為止的「最大連乘積」
        // 2. min_so_far: 走到目前為止的「最小連乘積 (可能為極小的負數)」
        // 3. result: 歷史最高紀錄
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i];

            // 核心技巧：因為接下來我們要覆蓋 max_so_far，
            // 但計算 min_so_far 時還需要用到「舊的」max_so_far，
            // 所以必須先用一個 temp 變數存起來！
            int temp_max = max({curr, max_so_far * curr, min_so_far * curr});
            
            // 同時考慮三種情況找最小值：自己重新開始、延續最大值乘自己、延續最小值乘自己
            min_so_far = min({curr, max_so_far * curr, min_so_far * curr});
            
            // 更新 max_so_far
            max_so_far = temp_max;

            // 挑戰歷史最高紀錄
            result = max(result, max_so_far);
        }

        return result;
    }
};