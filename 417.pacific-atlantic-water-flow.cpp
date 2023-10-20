class Solution {
    typedef pair<int, int> P;
public:
    vector<vector<int>> pacific;
    vector<vector<int>> atlantic;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        pacific.resize(row, vector<int>(col, 0));
        atlantic.resize(row, vector<int>(col, 0));

        queue<P> q;

        // Left edge
        for (int i = 0; i < row; i++) {
            q.push({i, 0});
            pacific[i][0] = 1;
        }

        // Top edge
        for (int i = 1; i < col; i++) {
            q.push({0, i});
            pacific[0][i] = 1;
        }

        while (!q.empty()) {
            auto idx = q.front();
            q.pop();

            int dx[4] = {0, 1, -1, 0};
            int dy[4] = {1, 0, 0, -1};
            for (int i = 0; i < 4; i++) {
                int newx = idx.first + dx[i];
                int newy = idx.second + dy[i];
                if (newx >= 0 && newx < row && newy >= 0 && newy < col 
                    && heights[newx][newy] >= heights[idx.first][idx.second]
                    && !pacific[newx][newy]) {
                    q.push({newx, newy});
                    pacific[newx][newy] = 1;
                }
            }
        }

        // Right edge
        for (int i = 0; i < row; i++) {
            q.push({i, col - 1});
            atlantic[i][col - 1] = 1;
        }

        // Bottom edge
        for (int i = 0; i < col; i++) {
            q.push({row - 1, i});
            atlantic[row - 1][i] = 1;
        }

        while (!q.empty()) {
            auto idx = q.front();
            q.pop();
            int dx[4] = {0, 1, -1, 0};
            int dy[4] = {1, 0, 0, -1};
            for (int i = 0; i < 4; i++) {
                int newx = idx.first + dx[i];
                int newy = idx.second + dy[i];
                if (newx >= 0 && newx < row && newy >= 0 && newy < col 
                    && heights[newx][newy] >= heights[idx.first][idx.second]
                    && !atlantic[newx][newy]) {
                    q.push({newx, newy});
                    atlantic[newx][newy] = 1;
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
