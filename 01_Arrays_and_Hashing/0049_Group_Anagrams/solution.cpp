#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// Naive solution (fixed with string used as array)
class NaiveSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        groups.reserve(strs.size());

        for(int i = 0; i < strs.size(); ++i) {
            string count(26, 0);
            for(auto c : strs[i]) {
                ++count[c-'a'];
            }
            groups[count].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};

class SubOptimalSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        groups.reserve(strs.size());

        // 優化 1：使用 const string& 避免在走訪時複製 strs 裡面的字串
        for(const string& s : strs) {
            string count(26, 0);
            for(char c : s) {
                ++count[c-'a'];
            }
            // 這裡 s 會被複製進 vector，這是必要的，因為我們要存結果
            groups[count].push_back(s); 
        }

        vector<vector<string>> result;
        // 優化 2：預先分配 result 的空間，避免動態擴容 (Reallocation)
        result.reserve(groups.size());
        
        // 優化 3：加上 `&`！直接讀取 Hash Map 裡的實體，絕對不複製！
        for(auto& pair : groups) { 
            // 優化 4：std::move (移動語意)
            // 告訴編譯器：「Hash Map 裡面的這個 vector 我不要了，直接把指標移交給 result」
            result.push_back(std::move(pair.second));
        }

        return result;
    }
};

// With Index Mapping
class OptimalSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Key: 26-byte 特徵字串, Value: 在 result 陣列中的索引位置
        unordered_map<string, int> groups;
        groups.reserve(strs.size());

        vector<vector<string>> result;
        result.reserve(strs.size());

        for (const string& s : strs) {
            // HPC 級特徵提取：絕對常數時間，零字串串接成本
            string key(26, 0); 
            for (char c : s) {
                key[c - 'a']++; 
            }

            // Index Mapping 技巧：查找是否出現過這個特徵
            auto it = groups.find(key);
            if (it != groups.end()) {
                // 如果有，直接用存好的 index，把字串塞進 result 的對應位置
                result[it->second].push_back(s);
            } else {
                // 如果沒有，把目前的 result 大小當作新的 index 存起來
                groups[key] = result.size();
                // 在 result 中開闢一個新的群組，並放入第一個字串
                result.push_back({s}); 
            }
        }

        // 不需要最後的 for 迴圈搬移，result 已經是完美的最終狀態了！
        return result;
    }
};