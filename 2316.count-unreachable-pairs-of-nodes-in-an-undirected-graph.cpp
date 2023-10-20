/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>* adj,vector<int>& visited,int node,int& count){
        count++;
        visited[node]=1;
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(adj,visited,it,count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> visited(n,0);
        vector<int> villages;
        for(int i=0;i<n;i++){
            int count=0;
            if(!visited[i]){
                dfs(adj,visited,i,count);
                villages.push_back(count);
            }
        }

        long long sum=accumulate(villages.begin(),villages.end(),0LL);
        long long ans=0;
        for(int i=0;i<villages.size();i++){
            ans+=villages[i]*(sum-villages[i]);
        }
        return ans/2;
        
    }
};
// @lc code=end

