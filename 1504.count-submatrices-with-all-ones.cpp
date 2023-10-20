/*
 * @lc app=leetcode id=1504 lang=cpp
 *
 * [1504] Count Submatrices With All Ones
 */

// @lc code=start
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> prefix(row,vector<int>(col,0));

        for(int i=0;i<row;i++){
            int x=0;
            for(int j=col-1;j>=0;j--){
                if(mat[i][j]){
                    x++;
                }
                else{
                    x=0;
                }
                prefix[i][j]=x;
            }
        }
        // use n^3 to find the solution
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int x=INT_MAX;
                for(int k=i;k<row;k++){
                    x=min(x,prefix[k][j]);
                    ans+=x;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

