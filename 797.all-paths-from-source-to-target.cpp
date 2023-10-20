/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> paths;
    void solve(vector<vector<int>>& graph,int node,vector<int>& path){
        path.push_back(node);
        int n=graph.size();
        if(node==n-1){
            paths.push_back(path);
        }

        for(auto it: graph[node]){
            solve(graph,it,path);
            path.pop_back();
        }


    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        solve(graph,0,path);
        return paths;
        
    }
};
// @lc code=end

