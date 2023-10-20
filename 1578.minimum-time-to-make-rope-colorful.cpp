/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int cost=0;
        int i=0,j=1;
        while(j<n){
            if(colors[i]!=colors[j]){
                i=j;
                j++;
            }
            else{
                cost+=min(neededTime[i],neededTime[j]);
                neededTime[i]=max(neededTime[i],neededTime[j]);
                j++;
            }
        }
        return cost;

        
    }
};
// @lc code=end

