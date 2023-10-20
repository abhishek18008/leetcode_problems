/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        if(n>0)
        {
           ans[1]=1; 
        }
        
        
        for(int i = 2; i <= n ; i++)
        {
            ans[i]=ans[i-1]+ans[i-2];
        }
        return ans[n];
        
    }
};
// @lc code=end

