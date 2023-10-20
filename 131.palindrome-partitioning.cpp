/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
   void solve(string s, int idx, vector<string>& temp, vector<vector<string>>& ans) {
    if (idx == s.size()) {
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < s.size(); i++) { // Fixed the loop header
        //check if from idx to i is palindrome
        if (ispalindrome(s, idx, i)) {
            temp.push_back(s.substr(idx, i - idx + 1));
            solve(s, i + 1, temp, ans); // Fixed the recursive call parameter
            temp.pop_back();
        }
    }
}

bool ispalindrome(string s, int idx, int end) {
    if (idx >= end) {
        return true;
    }
    if (s[idx] == s[end]) {
        return ispalindrome(s, idx + 1, end - 1);
    } else {
        return false;
    }
}

vector<vector<string>> partition(string s) {
    vector<string> temp;
    vector<vector<string>> ans;
    solve(s, 0, temp, ans);
    return ans;
}

};
// @lc code=end

