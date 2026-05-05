#include <iostream>
#include <vector>

using namespace std;

const static int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// Just use 0191 to count it, namely just count the bits for every number.
class NaiveSolution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i = 0; i < ans.size(); ++i) {
            int sum = 0, m = i;
            while (m != 0) {
                sum++;
                // 核心魔法：消除最低位的 1
                m &= (m - 1); 
            }
            ans[i] = sum;
        }
        return ans;
    }
};

class AIBetterSolution1 {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        // 0 的 1 數量是 0，陣列預設已經是 0，所以我們從 1 開始算
        for(int i = 1; i <= n; ++i) {
            // 核心魔法 DP 狀態轉移方程式：
            // 既然 i & (i - 1) 可以消掉 i 最低位的 1，
            // 那麼 i 的 1 數量，就等於「i & (i - 1) 的 1 數量」再加上剛剛被消掉的那 1 個！
            ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;
    }
};

class AIBetterSolution2 {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            // 核心魔法 DP 狀態轉移方程式：
            // ans[i >> 1] -> 拿到「除以 2」那個數字的答案 (歷史紀錄)
            // (i & 1)     -> 判斷目前的 i 是奇數還是偶數。奇數就 +1，偶數就 +0
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};