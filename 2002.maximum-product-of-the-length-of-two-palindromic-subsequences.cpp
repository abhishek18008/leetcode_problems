/*
 * @lc app=leetcode id=2002 lang=cpp
 *
 * [2002] Maximum Product of the Length of Two Palindromic Subsequences
 */

// @lc code=start
class Solution {
public:
    int maxi = 0;
    
    int longestPalindromeSubseq(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == s[n - j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }

    int maxpalindrome(string& s, set<int>& choosen) {
        string s1 = "";
        for (int i = 0; i < s.size(); i++) {
            if (choosen.count(i))
                s1.push_back(s[i]);
        }
        return longestPalindromeSubseq(s1);
    }

    void solve(string& s, set<int>& choosen, int idx) {
        if (idx == s.size()) {
            int len1 = maxpalindrome(s, choosen);
            string s2 = "";
            for (int i = 0; i < s.size(); i++) {
                if (!choosen.count(i))
                    s2.push_back(s[i]);
            }
            int len2 = longestPalindromeSubseq(s2);
            maxi = max(maxi, len1 * len2);
            return;
        }

        // Don't choose
        solve(s, choosen, idx + 1);

        // Choose idx
        choosen.insert(idx);
        solve(s, choosen, idx + 1);
        choosen.erase(idx);
    }

    int maxProduct(string s) {
        set<int> choosen;
        solve(s, choosen, 0);
        return maxi;
    }
};

// @lc code=end

