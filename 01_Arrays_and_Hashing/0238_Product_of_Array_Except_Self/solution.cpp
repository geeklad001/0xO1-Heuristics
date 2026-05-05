#include <iostream>
#include <vector>

using namespace std;

static int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class My_Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        vector<int> accumulated_product;
        vector<int> back_accumulated_product;
        answer.resize(nums.size());
        accumulated_product.resize(nums.size());
        back_accumulated_product.resize(nums.size());
        accumulated_product[0] = nums[0];
        back_accumulated_product[nums.size()-1] = nums[nums.size()-1];

        for (int i = 1; i < nums.size(); ++i) {
            accumulated_product[i] = accumulated_product[i-1] * nums[i];
            back_accumulated_product[nums.size()-1-i] = back_accumulated_product[nums.size()-i] * nums[nums.size()-1-i];
        }

        answer[0] = back_accumulated_product[1];
        answer[nums.size()-1] = accumulated_product[nums.size()-2];
        for (int i = 1; i < nums.size()-1; ++i) {
            answer[i] = accumulated_product[i-1] * back_accumulated_product[i+1];
        }
        
        return answer;
    }
};

// Better space complexity
class Better_Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // 直接宣告大小為 n 且初始值為 1 的 answer 陣列
        // 這是我們「唯一」配置的記憶體
        vector<int> answer(n, 1);

        // 第一階段：計算「前綴積 (左邊所有的乘積)」
        // 直接把前綴積存進 answer 陣列裡
        int left_product = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = left_product;     // 寫入當前位置左邊的所有乘積
            left_product *= nums[i];      // 更新 left_product 給下一個元素用
        }

        // 第二階段：計算「後綴積 (右邊所有的乘積)」並直接與 answer 相乘
        // 我們不需要另一個陣列，只需要一個變數記錄「從右邊累積過來的乘積」
        int right_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] *= right_product;   // 原本的左邊乘積 * 右邊乘積 = 最終答案！
            right_product *= nums[i];     // 更新 right_product 給前一個元素用
        }

        return answer;
    }
};