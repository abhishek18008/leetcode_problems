/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution {
public:
    int solve(vector<int>& arr, int k ,int index,vector<int> & dp){
        int n=arr.size();
        if(index==n)
        {
            dp[index]=0;
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        


        
        int sum=INT_MIN;
        int maxinpartition=INT_MIN;
        for(int i = index; i < min(index+k,n); i++)
        {
            maxinpartition=max(maxinpartition,arr[i]);
            int temp=solve(arr,k,i+1,dp);
            sum=max(sum,temp+maxinpartition*(i-index+1));
            
        }
        dp[index]=sum;
        return dp[index];
   
    }

    int  dp(vector<int> & arr,int k){
        int n=arr.size();
        vector<int> dp(n+1,-1);

        
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return dp(arr,k,0,dp);
        
    }
};
// @lc code=end

