/*
 * @lc app=leetcode id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
 */

// @lc code=start
class Solution {
public:
    typedef  long long ll;
    bool ispossible(vector<int>& nums,int maxi){
        int n=nums.size();
        ll buffer=maxi-nums[0];
        if(buffer<0) return false;
        
        for(int i=1;i<n;i++){
            ll temp=nums[i]-buffer;
            
            if(temp>maxi)
            return false;
            buffer=maxi-temp;   
        }
        return true;
    }


    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(!ispossible(nums,mid)){
                l=mid+1;
            }
            else {
                r=mid;
            }
        }
        return l;
        
    }
};
// @lc code=end

