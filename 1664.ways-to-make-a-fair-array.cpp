/*
 * @lc app=leetcode id=1664 lang=cpp
 *
 * [1664] Ways to Make a Fair Array
 */

// @lc code=start
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int>evenprefix(n);
        vector<int>oddprefix(n);

        int e=0,o=0;
        for(int i=0;i<n;i++){
            evenprefix[i]=e;
            oddprefix[i]=o;
            if(i%2==0)
            e+=nums[i];
            else
            o+=nums[i];
        }


        vector<int> evensuffix(n);
        vector<int> oddsuffix(n);
        e=0;
        o=0;
        for(int i=n-1;i>=0;i--){
            evensuffix[i]=e;
            oddsuffix[i]=o;
            if(i%2==0)
            e+=nums[i];
            else
            o+=nums[i];
        }

        int ans=0;
        //check 
        for(int i=0;i<n;i++){
            if(evenprefix[i]+oddsuffix[i]==oddprefix[i]+evensuffix[i])
            ans++;
        }
        return ans;
        
    }
};
// @lc code=end

