/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<int>* adj,vector<int>& colours,int node,int colour){
            if(colours[node]!=0){
                return colours[node] == colour;
            }
        
        colours[node]=colour;
        for(auto it: adj[node]){
            if(!dfs(adj,colours,it,-colour))
            return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //same as if graph is bipartite
        //create the adj list
        vector<int> adj[n+1];
        for(auto it: dislikes){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);        
        }

        vector<int> colours(n+1,0);
        for(int i=0;i<n;i++){
            if(!colours[i])
            {
                if(!dfs(adj,colours,i,1))
                return false;
            }
        }
        return true;
        
    }
};
// @lc code=end

