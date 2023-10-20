/*
 * @lc app=leetcode id=1646 lang=cpp
 *
 * [1646] Get Maximum in Generated Array
 */

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1)
        {
            return n;
        }
        
        
        vector<int> ans(n+1);
        ans[0]=0;
        ans[1]=1;
        int maxi=INT_MIN;
        for(int i = 2; i <=n; i++)
        {
            if(i%2==0)
            {
                ans[i]=ans[i/2];
            }
            else 
            {
                ans[i]=ans[i/2]+ans[i/2+1];
            }
            maxi=max(maxi,ans[i]);
            
        }
        return maxi;
        
        
    }
};
// @lc code=end

