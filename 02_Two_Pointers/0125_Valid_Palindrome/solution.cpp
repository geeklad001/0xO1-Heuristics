#include <iostream>
#include <string>
#include <cctype>

using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;

        int left = 0, right = s.size()-1;
        while (left < right) {
            while(left < s.size() && !isalnum(s[left])) {
                ++left;
            }

            while(right > 0 && !isalnum(s[right])) {
                --right;
            }

            if (left == s.size() || !isalnum(s[left])) return true;
            if (tolower(s[left]) != tolower(s[right])) return false;
            if (left == right) return true;

            ++left;
            --right;
        }
        return true;
    }
};