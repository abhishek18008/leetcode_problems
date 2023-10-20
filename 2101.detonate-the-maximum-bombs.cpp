/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int>* adj,vector<int>& visited,int node,int& count){
        visited[node]=1;
        count++;
        for(auto it: adj[node]){
            if(!visited[it])
            dfs(adj,visited,it,count);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                long long x=(bombs[i][0]-bombs[j][0]);
                long long y=(bombs[i][1]-bombs[j][1]);
                long long r=bombs[i][2];
                if(x*x+y*y<=r*r)
                adj[i].push_back(j);
                
            }
        }

        int maxi=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
             
            if(!visited[i]){
                int count=0;
                dfs(adj,visited,i,count);
                maxi=max(maxi,count);
            }
        }

        return maxi;
    }
};
// @lc code=end

