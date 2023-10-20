/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        vector<int> v(n+1);
        v[0]=0;
        if(n>0)
        {
           v[1]=1;
        }
        if(n>1)
        {
            v[2]=1;
        }

        
        for(int i = 3; i <= n; i++)
        {
            v[i]=v[i-1]+v[i-2]+v[i-3];
        }
        return v[n];
        
    }
};
// @lc code=end

