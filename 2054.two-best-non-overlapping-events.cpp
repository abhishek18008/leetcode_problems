/*
 * @lc app=leetcode id=2054 lang=cpp
 *
 * [2054] Two Best Non-Overlapping Events
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &events,int idx,int eventsleft){
        int n=events.size();
        //base case
        if(eventsleft==0 || idx==n) return 0;
        
        if(dp[idx][eventsleft]!=-1) return dp[idx][eventsleft];
        int val=0;
        //include the curr event if possible
         vector<int> tempVec = {events[idx][1] , INT_MAX , INT_MAX};
        int nextInd = upper_bound(events.begin() , events.end() , tempVec) - events.begin();
        
        val=max(val,events[idx][2]+solve(events,nextInd,eventsleft-1));

        // don't include the curr event
        val=max(val,solve(events,idx+1,eventsleft));
        return dp[idx][eventsleft]=val;

    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        dp.resize(n+1,vector<int>(3,-1));
        sort(events.begin(),events.end());
        return solve(events,0,2);
        
    }
};
// @lc code=end

