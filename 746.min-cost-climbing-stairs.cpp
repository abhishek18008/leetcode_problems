/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int> cost) {
        int n=cost.size();
        // vector<int> dist(n);
        // dist[n-1]=cost[n-1];
        // dist[n-2]=cost[n-2];
        for(int i = n-3; i >=0; i--)
        {
            cost[i]=min(cost[i+1],cost[i+2])+cost[i];
        }
        return min(cost[0],cost[1]);
        
        
    }
};
// @lc code=end

