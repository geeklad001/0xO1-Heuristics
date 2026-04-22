#include <iostream>
#include <map>

using namespace std;

// Using ordered tree
class NaiveSolution {
public:
    bool isAnagram(string s, string t) {
        // IO Speed Boosting
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        map<char, int> s_char_count;
        map<char, int> t_char_count;

        // count s chars
        for (auto c : s) {
            if(s_char_count.find(c) != s_char_count.end()) {
                ++s_char_count[c];
            }
            else {
                s_char_count[c] = 1;
            }
        }

        // count t chars
        for (auto c : t) {
            if(t_char_count.find(c) != t_char_count.end()) {
                ++t_char_count[c];
            }
            else {
                t_char_count[c] = 1;
            }
        }
        return s_char_count == t_char_count;
    }
};


// Optimal Solution using native array.
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 優化 1：長度不同，絕對不可能是 Anagram，直接 O(1) 拒絕
        if (s.length() != t.length()) {
            return false;
        }

        // 優化 2：使用原生 Array 取代 Map 作為計數器
        // 字母 a~z 剛好對應 ASCII 碼，長度 26 就夠了。初始化全為 0。
        int counts[26] = {0}; 

        // 優化 3：只需要一個迴圈
        // 利用 ASCII 碼的數學運算：'a' - 'a' = 0, 'b' - 'a' = 1, 'z' - 'a' = 25
        for (int i = 0; i < s.length(); i++) {
            counts[s[i] - 'a']++; // s 負責把計數器加上去
            counts[t[i] - 'a']--; // t 負責把計數器扣回來
        }

        // 優化 4：檢查陣列是否完美抵消
        // 如果真的是 Anagram，每個字母加減的次數會一樣，最後陣列應該全為 0
        for (int count : counts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};