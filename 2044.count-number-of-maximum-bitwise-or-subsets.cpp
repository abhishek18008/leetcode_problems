/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
class Solution {
public:
    int maxor=0;
    int count=0;
    void solve(vector<int>& nums,int idx,int temp){
        //base case
        if(idx==nums.size()){
            if(temp==maxor)
            count++;
            return;
        } 
        
        solve(nums,idx+1,temp|nums[idx]);
        solve(nums,idx+1,temp);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        //brute force
        int n=nums.size();
        for(auto it:nums){
            maxor=maxor|it;
        }
        //generate all subsets of nums
        int temp=0;
        
        //using bitmasking
        for(int i=0;i<(1<<n);i++){

            int temp=0;
            for(int j=0;j<n;j++){
                //check if this bit is set
                if((i&(1<<j))!=0)
                temp|=nums[j];
            }
            if(temp==maxor)
            count++;
        }
        return count;

    }
};
// @lc code=end

