/*
 * @lc app=leetcode id=2497 lang=cpp
 *
 * [2497] Maximum Star Sum of a Graph
 */

// @lc code=start
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        vector<int> adj[n];
        for(auto it:edges){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int maxisum=INT_MIN;
        for(int i=0;i<n;i++){
            int ans=vals[i];
            priority_queue<int, vector<int>, greater<int>> pq;
            for(auto it: adj[i]){
                pq.push(vals[it]);
                if(pq.size()>k)
                pq.pop();
            }
            while(!pq.empty()){
                if(pq.top()>0)
                ans+=pq.top();
                pq.pop();
            }
            maxisum=max(maxisum,ans);

        }
        return maxisum;

    }
};
// @lc code=end

