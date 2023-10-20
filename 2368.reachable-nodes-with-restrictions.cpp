/*
 * @lc app=leetcode id=2368 lang=cpp
 *
 * [2368] Reachable Nodes With Restrictions
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>* adj,vector<int>& visited,int node,int & count){
        count++;
        visited[node]=1;
        for(auto it:adj[node]){
            if(visited[it]==0){
                dfs(adj,visited,it,count);
            }
        }

    }


    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        //adj list
        vector<int> adj[n];
        for(auto it: edges){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> visited(n,0);
        // vector<int> unreachable(n,0);
        for(auto it: restricted)
        visited[it]=1;

        //perform a dfs
        int count=0;
        dfs(adj,visited,0,count);
        
        return count;
        
    }
};
// @lc code=end

