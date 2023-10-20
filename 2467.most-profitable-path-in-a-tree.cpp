/*
 * @lc app=leetcode id=2467 lang=cpp
 *
 * [2467] Most Profitable Path in a Tree
 */

// @lc code=start
class Solution {
public:
    bool path(vector<int>* adj,int node,vector<int>& visited,vector<int>& path){
        if(node==0)
        path.push_back(0);
        return true;

        for(auto it:edges){
            if(!visited[it]){
                if(path(adj,it,visited,path))
                path.push_back(node);
            }

        }
        return false;
    }


    int solve(vector<int>* adj,int node,int parent,vector<int> bobvisited){

    }


    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<int> adj(n);
        for(auto it: edges){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        //path for the bob
        vector<int> bobpath;
        vector<int> visited(n,0);
        path(adj,bob,visited,bobpath);
        reverse(bobpath.begin(),bobpath.end());

        vector<int> time(n,-1);
        time[0]=0;



    }
};
// @lc code=end

