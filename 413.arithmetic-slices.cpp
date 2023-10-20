/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return 0;
        }
        
        int count=0;
        vector<int> v(n+1,0);
        int prevdiff=nums[1]-nums[0];
        for(int i=2;i<n;i++){
            int diff=nums[i]-nums[i-1];
            if(diff==prevdiff){
                v[i]=v[i-1]+1;
            }
            else{
                prevdiff=diff;
            }
        }

        return accumulate(v.begin(),v.end(),0);
    }
};
// @lc code=end

