/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> reversed(n);
    vector<int> indegree(n);

    // Create the reversed graph and calculate the indegrees
    for(int i = 0; i < n; i++) {
        for(auto it : graph[i]) {
            reversed[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;

    // Add nodes with zero indegree to the queue
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto neighbor : reversed[node]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Sort the eventual safe nodes before returning
    sort(ans.begin(), ans.end());

    return ans;
}

};
// @lc code=end

