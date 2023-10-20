/*
 * @lc app=leetcode id=2275 lang=cpp
 *
 * [2275] Largest Combination With Bitwise AND Greater Than Zero
 */

// @lc code=start
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        int maxi=0;
        //iterate through 31 bits and see max 
        for(int k=0;k<31;k++){
            int count=0;
            for(int i=0;i<n;i++){
                if((candidates[i]&(1<<k))!=0)
                count++;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};
// @lc code=end

