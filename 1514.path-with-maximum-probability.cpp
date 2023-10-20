/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
         //make the adj list
         vector<pair<double,int>> adj[n];
         for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            double w=succProb[i];
            adj[x].push_back({w,y});
            adj[y].push_back({w,x});
         }

        vector<double> maxprob(n,0.0);
        vector<int> visited(n,0);
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        maxprob[start_node]=1.0;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int node=x.second;
            double prob_node=x.first;
            if(!visited[node]){
                visited[node]=1;
                for(auto it : adj[node]){
                    if(maxprob[it.second]<(double)prob_node*it.first){
                        maxprob[it.second]=(double)prob_node*it.first;
                        pq.push({maxprob[it.second],it.second});
                    }
                }
            }
        }
        return maxprob[end_node];
        
    }
};
// @lc code=end

