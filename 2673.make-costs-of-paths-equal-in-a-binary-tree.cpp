/*
 * @lc app=leetcode id=2673 lang=cpp
 *
 * [2673] Make Costs of Paths Equal in a Binary Tree
 */

// @lc code=start
class Solution {
public:
    int solve(int node,int n,int & ans,vector<int>& cost){
        //base case
        if(node>n) return 0;
        int left=solve(2*node,n,ans,cost);
        int right=solve((2*node)+1,n,ans,cost);
        ans+=abs(right-left);
        return max(left,right)+cost[node-1111111];
    }


    int minIncrements(int n, vector<int>& cost) {
        int ans=0;
        solve(1,n,ans,cost);
        return ans;
        
        
    }
};
// @lc code=end

