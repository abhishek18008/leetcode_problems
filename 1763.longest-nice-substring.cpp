/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
 */

// @lc code=start
class Solution {
public:
 bool isgood(string s, int i, int j) {
    unordered_map<char, bool> mp;
    for (int k = i; k <= j; k++) {
        mp[s[k]] = true;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if ((int)it->first < 97) {
            if (mp.find((char)(it->first + 32)) != mp.end()) {
                continue;
            } else {
                return false;
            }
        } else {
            if (mp.find((char)(it->first - 32)) != mp.end()) {
                continue;
            } else {
                return false;
            }
        }
    }

    return true;
}

string longestNiceSubstring(string s) {
    int n = s.size();
    string ans;
    int maxlen = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isgood(s, i, j)) {
                if (j - i + 1 > maxlen) {
                    maxlen = j - i + 1;
                    ans = s.substr(i, maxlen);
                }
            }
        }
    }
    return ans;
}

};
// @lc code=end

