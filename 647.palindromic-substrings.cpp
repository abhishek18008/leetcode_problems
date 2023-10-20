/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int solve(vector<vector<int>>& dp,int i,int j,string& s){
        if(i>=j){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]!=s[j])
        {
            dp[i][j]=0;
            return 0;
        }

        else{
            dp[i][j]= solve(dp,i+1,j-1,s);
            return dp[i][j];
        }

    }

    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int ans=0; 
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans+=solve(dp,i,j,s);
            }
        }
        
        return ans;
        }
        
        
        
};

        

// @lc code=end

