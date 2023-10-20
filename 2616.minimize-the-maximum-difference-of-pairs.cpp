/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
class Solution {
public:
    bool ispossible(vector<int>& nums,int p, int maxdiff){
        int n=nums.size();
        int i=0,j=1;
        int pairfound=0;
        while(j<n){
            if(nums[j]-nums[i]<=maxdiff){
                pairfound++;
                i=j+1;
                j=i+1;
            }
            else{
                i++;
                j++;
            }

        }
        if(pairfound>=p) return true;
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        // try binary serach on ans
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=nums[n-1]-nums[0];
        while(l<r){
            int mid=(l+r)/2;
            if(!ispossible(nums,p,mid)){
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

