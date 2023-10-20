/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
        vector<vector<int>> dp;
    int solve(string & s,string & t,int i ,int j){
        //base case
        //if either of i and j is out of bound return size of other 
        int n=s.size();
        int m=t.size();
        if(i==n ){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        //if both char are same
        int ans=INT_MAX;
        if(s[i]==t[j]){
            ans=min(ans,solve(s,t,i+1,j+1));
        }
        else{
            ans=min(solve(s,t,i+1,j),solve(s,t,i,j+1))+1;
        }
        return dp[i][j]=ans;
    }



    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        
        return solve(word1,word2,0,0);
        
    }
};
// @lc code=end

