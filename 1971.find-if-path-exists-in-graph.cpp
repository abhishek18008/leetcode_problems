/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution {
public:
    bool pathExists(vector<int>* adj,int source,int destination,vector<int>& visited){
        visited[source]=1;
        for(auto it : adj[source]){
            if(it==destination)
            return true;
        }

        for(auto it: adj[source]){
            if(!visited[it]){
                bool ans=pathExists(adj,it,destination,visited);
                if(ans)
                return true;
            }
            
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1)
        return true;
  
        vector<int> adj[n];
        vector<int> visited(n,0);
        
        for(auto it : edges){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        return pathExists(adj,source,destination,visited);
        
        
    }
};
// @lc code=end

