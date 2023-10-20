/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool solve(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string word, int idx) {
    int wordsize = word.size();
    int row = board.size();
    int col = board[0].size();
    // mark visited as marked
    visited[i][j] = 1;

    if (idx == wordsize)
        return true;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    for (int k = 0; k < 4; k++) {
        int newx = i + dx[k];
        int newy = j + dy[k];
        if (newx >= 0 && newx < row && newy >= 0 && newy < col &&
            visited[newx][newy] == 0 &&
            board[newx][newy] == word[idx]) {
            bool temp = solve(board, visited, newx, newy, word, idx + 1);
            if (temp)
                return true;
        }
    }
    visited[i][j] = 0; // Mark the cell as unvisited when backtracking
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) { // <-- Corrected the loop variable to 'j'
            if (board[i][j] == word[0]) {
                vector<vector<int>> visited(row, vector<int>(col, 0));
                bool ans = solve(board, visited, i, j, word, 1);
                if (ans)
                    return true;
            }
        }
    }
    return false;
}

};
// @lc code=end

