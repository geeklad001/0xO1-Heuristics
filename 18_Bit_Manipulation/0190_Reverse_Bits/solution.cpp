#include <iostream>
#include <cstdint>
using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// Intuition: Exchange the bits, from start to the middle (You only need to exchange half of the number of the bits.)
class MySolution {
public:
    int reverseBits(int n) {
        for (int i = 0; i < 16; ++i) {
            int big_bit = n & ((1u << 31) >> i);
            int small_bit = n & (0b1 << i);
            n ^= big_bit;
            n ^= small_bit;
            n ^= small_bit << (32-2*i - 1);
            n ^= big_bit >> (32-2*i - 1);
        }
        return n;
    }
};

class StandardFastSolution {
public:
    // 嚴格遵守 uint32_t，杜絕有號整數的算術右移災難
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        
        // 32-bit 整數，固定推 32 次
        for (int i = 0; i < 32; ++i) {
            // 1. 把 ans 往左推一格，騰出最右邊的空位
            // 2. n & 1 取出 n 目前最右邊的位元
            // 3. 用 | (OR) 把那個位元塞進 ans 的空位裡
            ans = (ans << 1) | (n & 1);
            
            // n 往右退一格，準備下一次迴圈取下一個位元
            n >>= 1;
        }
        
        return ans;
    }
};

// No Loop
class HPCSolution {
public:
    uint32_t reverseBits(uint32_t n) {
        // 就像切蛋糕一樣，左右對調
        // 1. 左右相鄰的 1 bit 對調 (0x55555555 是 01010101...)
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        // 2. 左右相鄰的 2 bits 對調 (0x33333333 是 00110011...)
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        // 3. 左右相鄰的 4 bits (Nibbles) 對調
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        // 4. 左右相鄰的 8 bits (Bytes) 對調
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        // 5. 左右相鄰的 16 bits (Half-words) 對調
        n = (n >> 16) | (n << 16);
        
        return n;
    }
};