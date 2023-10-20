/*
 * @lc app=leetcode id=553 lang=cpp
 *
 * [553] Optimal Division
 */

// @lc code=start
class Solution {
public:

    float solve(vector<int>& nums,int si,int ei){
        //base case 
        // when there is only one elemnt present in the subarray
        if(si==ei)
        return nums[si];
        float maxans=INT_MIN;
        for(float i=si;i<ei;i++){
            float left=solve(nums,si,si+i);
            float right=solve(nums,si+i+1,ei);
            maxans=max(maxans,left/right);
        }
        return maxans;
    }




    string optimalDivision(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return to_string(nums[0]);
        if(n==2) return to_string(nums[0])+"/"+to_string(nums[1]);
        
        //when n is greater than 2
        string ans=to_string(nums[0]);
        ans.append("/(");
        for(int i=1;i<n-1;i++){
            ans.append(to_string(nums[i])+"/");
        }
        ans.append(to_string(nums[n-1]));
        ans.append(")");
        return ans;
        
        
    }
};
// @lc code=end

