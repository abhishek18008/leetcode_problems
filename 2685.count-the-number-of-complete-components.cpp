/*
 * @lc app=leetcode id=2685 lang=cpp
 *
 * [2685] Count the Number of Complete Components
 */

// @lc code=start
class Solution {
public:
    int dfs(vector<int>* adj, vector<int>& visited, int node, int& v) {
    visited[node] = 1;
    v++;
    int count = adj[node].size();
    for(auto it : adj[node]) {
        if(!visited[it])
            count += dfs(adj, visited, it, v);
    }
    return count;
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    // Make the adjacency list
    vector<int> adj[n];
    
    for(int i = 0; i < edges.size(); i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> visited(n, 0);
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            int v = 0;
            int numEdges = dfs(adj, visited, i, v);
            
            // Check if the connected component is complete
            if(numEdges == v * (v - 1) )
                count++;
        }
    }
    
    return count;
}


};
// @lc code=end

