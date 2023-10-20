/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution {
public:
    int count = 0;

void dfs(vector<pair<int, int>>* adj, int node, int parent) {
    for (auto it : adj[node]) {
        if (it.first != parent) {
            if (it.second == 0) {
                count++;
            }
            dfs(adj, it.first, node);
        }
    }
}

int minReorder(int n, vector<vector<int>>& connections) {
    vector<pair<int, int>> adj[n];
    for (auto it : connections) {
        int x = it[0];
        int y = it[1];
        
        // For the edge x -> y, add the edge (x, 0) to indicate the original edge direction.
        adj[x].push_back({y, 0});
        
        // For the edge y -> x, add the edge (y, 1) to indicate the reversed edge direction.
        adj[y].push_back({x, 1});
    }
    dfs(adj, 0, -1);
    return count;
}

};
// @lc code=end

