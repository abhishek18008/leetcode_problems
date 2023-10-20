/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<int>* adj,vector<int> &colours,int node,int colourassigned){
        //check if currently assigned colour is valid
        for(auto it: adj[node]){
            if(colours[it]==colourassigned)
            return false;
        }

        colours[node-1]=colourassigned;
        for(auto it: adj[node]){
            if(colours[it]==0){
                for(int i=1;i<=4;i++){
                    if(dfs(adj,colours,it,i)){
                        break;
                    }
                }
            }
        }
        return true;

    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        for(auto it: paths){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[2]);
        }

        vector<int> colours(n+1,0);
        for(int i=0;i<n;i++){
            if(colour[i]==0)
            dfs(adj,colours,i,1);
        }
        return colours;

    }
};
// @lc code=end

