/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */

// @lc code=start
// class disjointset{
//     public:
//     vector<int>rank;
//     vector<int> parent;

//     disjointset(int n){
//         rank.resize(n+1,0);
//         parent.resize(n+1);
//         for(int i=0;i<=n;i++){
//             parent[i]=i;
//         }
//     }

//     int find(int v){
//         if(parent[v]==v)  return v;
//         return parent[v]=find(parent[v]);
//     }

//     void Union(int x,int y){
//         int px=find(x);
//         int py=find(y);
//         if(px==py) return;
//         if(rank[px]>rank[py])
//         parent[py]=px;
//         else if(rank[x]>rank[y])
//         parent[px]=py;
//         else{
//             parent[px]=py;
//             rank[py]++;
//         }
//     }

// };

class Solution {
public:

    typedef pair<int,int> P;

    void dfs(vector<P>* adj,vector<int>& visited,int node,int& mini){
        visited[node]=1;
        for(auto it: adj[node]){
            mini=min(mini,it.second);
            if(!visited[it.first])
            dfs(adj,visited,it.first,mini);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
    
        vector<P> adj[n+1];
        for(auto it: roads){
            int x=it[0];
            int y=it[1];
            int w=it[2];
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
        }


        vector<int> visited(n+1,0);
        int mini=INT_MAX;
        dfs(adj,visited,1,mini);
        return mini;
        
    }
};
// @lc code=end

