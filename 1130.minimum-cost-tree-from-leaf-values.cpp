/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
class Solution {
public:
    
    int solve(vector<int>& arr, int sidx, int eidx,vector<vector<int>>& dp) {
    //base case
    if (sidx == eidx) {
        return 0;
    }
    if(dp[sidx][eidx]!=-1){
        return dp[sidx][eidx];
    }

    int mini = 1e9;
    for (int i = sidx; i < eidx; i++) {
        int left = solve(arr, sidx, i,dp);
        int right = solve(arr, i + 1, eidx,dp);
        int leftmax = *max_element(arr.begin() + sidx, arr.begin() + i + 1);
        int rightmax = *max_element(arr.begin() + i + 1, arr.begin() + eidx + 1);
        mini = min(leftmax * rightmax + left + right, mini);
    }
    dp[sidx][eidx]=mini;
    return mini;
}


    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size(); 
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(arr,0,n-1,dp);
        
        
    }
};
// @lc code=end

