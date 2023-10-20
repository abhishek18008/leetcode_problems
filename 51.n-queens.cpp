/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    bool isSafe(int r,int c,vector<string> config){
        int n=config.size();
        //check column
        for(int i=0;i<n;i++){
            if(config[i][c]=='Q')
            return false;
        }

        //check diagonally
        //check in top left
        int i=r;
        int j=c;
        while(i>=0 && i<n && j>=0 && j<n){
            if(config[i][j]=='Q')
            return false;
            i--;
            j--;
        }
        i=r;
        j=c;

        //check in top right
        while(i>=0 && i<n && j>=0 && j<n){
            if(config[i][j]=='Q')
            return false;
            i--;
            j++;
        }
        i=r;
        j=c;

        //check in left down
         while(i>=0 && i<n && j>=0 && j<n){
            if(config[i][j]=='Q')
            return false;
            i++;
            j--;
        }
        i=r;
        j=c;

        //check in down right
         while(i>=0 && i<n && j>=0 && j<n){
            if(config[i][j]=='Q')
            return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans,vector<string>&temp,int N,int row){
        
        if(row==N){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<N;i++){
            if(isSafe(row,i,temp)){
                temp[row][i]='Q';
                solve(ans,temp,N,row+1);
                temp[row][i]='.';
            }

        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> temp(n,s);
        solve(ans,temp,n,0);
        return ans;
        
    }
};
// @lc code=end

