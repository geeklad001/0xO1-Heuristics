#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// First thought solution: search for the results using biggest coins first as a greedy approach and performs a DFS.
class BugSolution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // vector coins is now sorted.
        sort(coins.begin(), coins.end());
        return findAmount(coins, amount);
    }

    int findAmount(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        int biggestCoinValue = coins.at(coins.size() - 1);
        int biggestCoinCount = amount / biggestCoinValue;

        while(biggestCoinCount >= 0) {
            if (biggestCoinCount * biggestCoinValue == amount) 
                return biggestCoinCount;
            else {
                int remainingAmount = amount - biggestCoinCount * biggestCoinValue;
                vector<int> remainingCoins(coins.begin(), coins.end() - 1);
                int result = findAmount(remainingCoins, remainingAmount);
                if (result != -1) {
                    return biggestCoinCount + result;
                }
            }
            --biggestCoinCount;
        }
        
        return -1;
    }
};

class BugFixedTLESolution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        return findAmount(coins, amount);
    }

    int findAmount(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        int biggestCoinValue = coins.at(coins.size() - 1);
        int biggestCoinCount = amount / biggestCoinValue;

        // 新增：用來記錄所有可能組合中的「最少硬幣數」
        int minCoins = INT_MAX; 

        while(biggestCoinCount >= 0) {
            if (biggestCoinCount * biggestCoinValue == amount) {
                // 如果剛好湊滿，不要 return，而是與 minCoins 比較取較小值
                minCoins = min(minCoins, biggestCoinCount);
            } 
            else {
                int remainingAmount = amount - biggestCoinCount * biggestCoinValue;
                vector<int> remainingCoins(coins.begin(), coins.end() - 1);
                int result = findAmount(remainingCoins, remainingAmount);
                
                if (result != -1) {
                    // 如果這條路徑走得通，一樣不要 return，更新 minCoins
                    minCoins = min(minCoins, biggestCoinCount + result);
                }
            }
            --biggestCoinCount;
        }
        
        // 迴圈結束後，如果 minCoins 還是 INT_MAX，代表所有路徑都湊不出來
        if (minCoins == INT_MAX) {
            return -1;
        }
        return minCoins;
    }
};

#include <vector>
#include <algorithm>

using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class OptimizedSolution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] 代表「湊滿 i 元所需的最少硬幣數」
        // 我們把陣列初始值設為 amount + 1。
        // 因為就算全部用 1 元硬幣，最多也只需要 amount 個。
        // 所以 amount + 1 在這裡的意義等同於「無限大 (無法湊成)」。
        vector<int> dp(amount + 1, amount + 1);
        
        // Base case: 湊滿 0 元需要 0 個硬幣
        dp[0] = 0;

        // 由下往上，從小金額一路算到目標金額 amount
        for (int i = 1; i <= amount; ++i) {
            // 對於當前要湊的金額 i，我們嘗試每一種硬幣
            for (int coin : coins) {
                // 如果這個硬幣的面額「裝得下」當前金額
                if (i - coin >= 0) {
                    // 狀態轉移方程式核心：
                    // 要湊滿 i 元的最少硬幣數，就是「目前紀錄的 dp[i]」與
                    // 「湊滿 (i - coin) 元的最少硬幣數 + 1 枚當前硬幣」兩者取最小值
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // 迴圈結束後，如果 dp[amount] 還是初始值，代表湊不出來
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
