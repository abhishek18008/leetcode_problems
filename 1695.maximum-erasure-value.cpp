/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int i=0,j=0;
        int maxi=0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[nums[j]]++;
            sum+=nums[j];
            // if all elements are unique in the curr window size of map will be same as the 
            // size of the wiindow
            while(mp.size()<j-i+1){
                mp[nums[i]]--;
                sum-=nums[i];
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            maxi=max(maxi,sum);
            j++;

        }
        return maxi;
        
    }
};
// @lc code=end

