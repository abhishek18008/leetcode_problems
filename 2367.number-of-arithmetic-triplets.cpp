/*
 * @lc app=leetcode id=2367 lang=cpp
 *
 * [2367] Number of Arithmetic Triplets
 */

// @lc code=start
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        //brute force
        int n=nums.size();
        int count=0;
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(mp.find(x-diff)!=mp.end() && mp.find(x+diff)!=mp.end())
            count++;
        }
        return count;
        
    }
};
// @lc code=end

