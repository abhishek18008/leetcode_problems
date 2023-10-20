/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int index,vector<int>& dp) {
    // Base case
    int n = days.size();
    if (index >= n) {
        return 0;
    }

    if(dp[index]!=-1)
    return dp[index];

    int plan1 = costs[0] + solve(days, costs, index + 1,dp);

    // For 7 days plan
    int nextindex = index;
    while (nextindex < n && days[nextindex] < days[index] + 7) {
        nextindex++;
    }
    int plan7 = costs[1] + solve(days, costs, nextindex,dp);

    // For 30 days plan
    int index30 = index;
    while (index30 < n && days[index30] < days[index] + 30) {
        index30++;
    }
    int plan30 = costs[2] + solve(days, costs, index30,dp);

    return dp[index]=min({plan1, plan7, plan30});
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n=days.size();
    vector<int> dp(n+1,-1);
    return solve(days, costs, 0,dp);
}

};
// @lc code=end

