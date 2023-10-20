/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        //find the max value of v[i]-i 
        vector<int> endgain(n);
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,values[i]-i);
            endgain[i]=maxi;
        }

        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            ans=max(ans,values[i]+i+endgain[i+1]);
        }
        return ans;
        
    }
};
// @lc code=end

