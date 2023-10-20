/*
 * @lc app=leetcode id=1292 lang=cpp
 *
 * [1292] Maximum Side Length of a Square with Sum Less than or Equal to Threshold
 */

// @lc code=start
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        //calculate the perfix array
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> prefixsum(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefixsum[i][j]=prefixsum[i-1][j]+prefixsum[i][j-1]-prefixsum[i-1][j-1]+mat[i-1][j-1];
            }
        }

        for( int k = min(m, n); k > 0; --k){ //iteration for the matrix size
            for(int i = k; i <= m; i++){
                for(int j = k; j <= n; ++j){
                    int sum = prefixsum[i][j] - prefixsum[i][j-k] - prefixsum[i-k][j] + prefixsum[i-k][j-k];
                    if(sum <= threshold){
                        return k;
                    }
                }
            }
        }    
        return 0;    
    }
    
};
// @lc code=end

