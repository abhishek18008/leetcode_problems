/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int i=0,j=0;
        //find the window with size n-k with the min sum
        int sum=0;
        int mini=1e9;
        while(j<n){
            sum+=cardPoints[j];
            if(j-i+1>n-k){
                sum-=cardPoints[i];
                i++;
            }
            if(j-i+1==n-k)
            mini=min(mini,sum);
            j++;
        }
        return accumulate(cardPoints.begin(),cardPoints.end(),0)-mini;
        
    }
};
// @lc code=end

