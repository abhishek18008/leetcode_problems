/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
//MERA CODE HAI
class Solution {
public:
   bool isValid(vector<vector<char>>& board, char num, int r, int c) {
    for (int i = 0; i < 9; i++) {
        // row check
        if (board[r][i] == num)
            return false;
        // col check
        if (board[i][c] == num)
            return false;

        // submatrix check
        int subboxRowStart = 3 * (r / 3);
        int subboxColStart = 3 * (c / 3);
        if (board[subboxRowStart + i / 3][subboxColStart + i % 3] == num)
            return false;
        

    }
    
    return true;
}


    

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isValid(board,c,i,j)){
                        board[i][j]=c;
                        if(solve(board)){
                            return true;
                        }
                        else{
                            board[i][j]='.';
                        }
                    }
                }
              return false;
              //kyon karna hai
            }
        }
    }
    return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
         solve(board); 
         return;
    }
};
// @lc code=end

