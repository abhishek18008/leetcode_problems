/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution {
public:
    int atmost(vector<int>& nums,int k){
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans+=j-i+1;
            j++;

        }
        return ans;
        
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
        
    }
};
// @lc code=end

