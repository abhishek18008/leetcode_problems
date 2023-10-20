/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution {
public:
    int solve(string& s1,string& s2,int i,int j,vector<vector<int>>& dp){
        //base case
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=s1.size()){
            int sum=0;
            for(int k=j;k<s2.size();k++){
                sum+=s2[k];
            }
            return sum;
        }

        if(j>=s2.size()){
            int sum=0;
            for(int k=i;k<s1.size();k++){
                sum+=s1[k];
            }
            return sum;
        }

        if(s1[i]==s2[j]){
            return dp[i][j]=solve(s1,s2,i+1,j+1,dp);
        }

        else{
            int keepi=solve(s1,s2,i,j+1,dp);
            int keepj=solve(s1,s2,i+1,j,dp);
            return dp[i][j]=min(keepi+(int)s2[j],keepj+(int)s1[i]);
        }

    }



    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,0,0,dp); 
    }
};
// @lc code=end

