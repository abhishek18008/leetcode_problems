/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public: 

    int solve(string s,string t,int i,int j){
        int n=s.size();
        int m=t.size();
        if(i==n || j==m) return 0;

        int ifsame=0;
        if(s[i]==t[j]){
            ifsame=solve(s,t,i+1,j+1)+1;
        }
        int ignorei=solve(s,t,i+1,j);
        int ignorej=solve(s,t,i,j+1);
        return max(ifsame,max(ignorei,ignorej));
    }




   int longestCommonSubsequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i] == t[j]) {  // Use '==' for comparison
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[0][0];
}

};
// @lc code=end

