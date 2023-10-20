/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		// dp.resize(size(A), vector<int>(size(B), -1));
		// solve(A, B, 0, 0);
		// return ans;
        int n=A.size();
        int m=B.size();
        int maxi=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxi=max(maxi,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return maxi;
	}


	// int solve(vector<int>& A, vector<int>& B, int i, int j) {
	// 	if(i >= size(A) || j >= size(B)) return 0;
	// 	if(dp[i][j] != -1) return dp[i][j];
	// 	solve(A, B, i+1, j), solve(A, B, i, j+1);
	// 	dp[i][j] = A[i] == B[j] ? solve(A, B, i+1, j+1) + 1 : 0;  // store the result for state (i, j) for future
	// 	ans = max(ans, dp[i][j]);
	// 	return dp[i][j];
	// }
};	
// @lc code=end

