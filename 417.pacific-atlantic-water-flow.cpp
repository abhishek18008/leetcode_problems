/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> pacific;
    vector<vector<int>> Atlantic;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();

        pacific.resize(row,vector<int>(col,0));
        Atlantic.resize(row,vector<int>(col,0));

        //use bfs to find all points from where water can flow

        //left edge
        for(int i=0;i<)
    }
};
// @lc code=end

