/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution {
public:
    int solve(vector<vector<int>>& matrix,int i,int j,int& sum){
        cout<<sum<<endl;
        //base case 
        int row=matrix.size();
        int col=matrix[0].size();
        if(i==row || j==col)
        {
            return 0;
        }
        //right call
        int right=solve(matrix,i+1,j,sum);
        
        //down call 
        int down=solve(matrix,i,j+1,sum);
        
        // diagonal call
        int diagonal=solve(matrix,i+1,j+1,sum);
        
        if(matrix[i][j]==1)
        {
            int ans= min(right,min(down,diagonal))+1;
            sum+=ans;
            return ans;
        }
        else 
        {
            return 0;
        }
        
        
        
    }
    
    int countSquares(vector<vector<int>>& matrix) {
       int sum=0;
       solve(matrix,0,0,sum);
       return sum;
    
        
    }
};
// @lc code=end

