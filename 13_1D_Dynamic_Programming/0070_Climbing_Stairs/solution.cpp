#include <iostream>
using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}();

class MySolution {
public:
    int climbStairs(int n) {
        int ways[46];
        ways[0] = 1;
        ways[1] = 1;
        for (int i = 2; i < 46; ++i) {
            ways[i] = ways[i-1] + ways[i-2];
        }
        
        return ways[n];
    }
};

class AISolution {
public:
    int climbStairs(int n) {
        // 如果樓梯只有 1 階或 2 階，直接回傳對應的走法數
        if (n <= 2) {
            return n;
        }
        
        // 我們只需要記住「前一階」和「前兩階」的走法數
        // 對應你的陣列，這就是 ways[1] 和 ways[2]
        int prev2 = 1; // 走到第 1 階有 1 種方法
        int prev1 = 2; // 走到第 2 階有 2 種方法
        
        int current = 0;
        
        // 從第 3 階開始算，算到我們需要的 n 階就立刻停止
        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2; // 當前這階的走法 = 前一階 + 前兩階
            
            // 狀態滾動 (Shift)：
            // 為了準備計算下一階，原本的 prev1 變成了新的 prev2
            // 原本算出來的 current 變成了新的 prev1
            prev2 = prev1;
            prev1 = current;
        }
        
        return current;
    }
};