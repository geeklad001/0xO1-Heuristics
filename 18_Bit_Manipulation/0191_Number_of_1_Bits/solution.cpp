#include <iostream>
using namespace std;

const static int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}();

class Solution {
public:
    int hammingWeight(int n) {
        int sum = 0;
        while(n>0) {
            sum += int(n & 0b1);
            n >>= 1;
        }
        return sum;
    }
};

// 但這比較花空間
class EvenBetterSolution {
public:
    int hammingWeight(int n) {
        int sum = 0;
        
        // 使用 != 0，完美相容正數與負數
        while (n != 0) {
            sum++;
            // 核心魔法：消除最低位的 1
            n &= (n - 1); 
        }
        
        return sum;
    }
};