/*
 * @lc app=leetcode id=1558 lang=cpp
 *
 * [1558] Minimum Numbers of Function Calls to Make Target Array
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int k=31;
        while(k--){
            int x=0;
            for(int i=0;i<n;i++){
                
                if(nums[i]&1){
                    count++;
                    nums[i]--;
                }
                if(nums[i]!=0){
                    x++;
                }
                nums[i]=(nums[i]/2);
            }
            if(x){
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

