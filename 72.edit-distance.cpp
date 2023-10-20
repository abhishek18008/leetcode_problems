/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s ,string &t,int idx1,int idx2){
        if(idx1==s.size())
        return t.size()-idx2;
        if(idx2==t.size()){
            return s.size()-idx1;
        }
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int mini=INT_MAX;
        if(s[idx1]==t[idx2]){
            mini=min(mini,solve(s,t,idx1+1,idx2+1));
        }
        mini=min(mini,solve(s,t,idx1+1,idx2)+1);
        mini=min(mini,solve(s,t,idx1,idx2+1)+1);
        mini=min(mini,solve(s,t,idx1+1,idx2+1)+1);
        return dp[idx1][idx2]=mini;


    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        //solve using tabulation
        
        
    }
};
// @lc code=end

