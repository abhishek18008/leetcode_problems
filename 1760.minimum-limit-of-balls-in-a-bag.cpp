/*
 * @lc app=leetcode id=1760 lang=cpp
 *
 * [1760] Minimum Limit of Balls in a Bag
 */

// @lc code=start
class Solution {
public:
    int n;
    bool ispossible(vector<int>& nums,int mini,int k){
        int opsrequired=0;
        for(int i=0;i<n;i++){
            opsrequired+=(nums[i]-1)/mini;

        }
        if(opsrequired<=k) return true;
        return false;
    }



    int minimumSize(vector<int>& nums, int maxOperations) {
         n=nums.size();
        int r=*max_element(nums.begin(),nums.end());
        int l=1;
        while(l<r){
            int mid=(l+r)/2;
            if(!ispossible(nums,mid,maxOperations)){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;

        
    }
};
// @lc code=end

