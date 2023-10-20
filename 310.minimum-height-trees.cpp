/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it: edges){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

         vector<int> indegree(n,0);
         vector<int> leaves;
         for(int i=0;i<n;i++){
            indegree[i]=adj[i].size();
            if(adj[i].size()<=1)
            leaves.push_back(i);
         }


        vector<int> newleaves;
         while(n>2){
            for(auto it : leaves){
                for(auto j: adj[it]){
                    indegree[j]--;
                    if(indegree[j]==1)
                    newleaves.push_back(j);
                }
            }
            n-=leaves.size();
            leaves.clear();
            leaves=newleaves;
            newleaves.clear();

         }

         return leaves;  
    }
};
// @lc code=end

