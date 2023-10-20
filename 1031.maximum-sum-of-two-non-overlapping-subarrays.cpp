/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        //generate prefix sum for firstlen subarray
        vector<int> prefixfirslen(n);
        int sum=0;
        int i=0,j=0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1!=firstLen)
            j++;
            else{
                prefixfirslen[i]=sum;
                sum-=nums[i];
                i++;
                j++;
            }
        }

        //generate prefix sum for secondlen subarray
        vector<int> prefixsecondlen(n);
        sum=0,i=0,j=0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1!=secondLen)
            j++;
            else{
                prefixsecondlen[i]=sum;
                sum-=nums[i];
                i++;
                j++;
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int temp=prefixfirslen[i];
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                if(j>=i && j<i+firstLen || j<i && j>i-secondLen)
                continue;
                maxi=max(maxi,prefixsecondlen[j]);
            }
            ans=max(ans,temp+maxi);
        }

        

        return ans;


        
    }
};
// @lc code=end

