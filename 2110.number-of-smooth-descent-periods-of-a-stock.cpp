/*
 * @lc app=leetcode id=2110 lang=cpp
 *
 * [2110] Number of Smooth Descent Periods of a Stock
 */

// @lc code=start
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 1;
        long long ans=0;
        int j=0;
        for(int i=1;i<n;i++){
            if(prices[i-1]-prices[i]==1){
                continue;
            }
            else{
                int regionlength=i-j;
                j=i;
                ans+=(long long)(regionlength*(regionlength+1))/2;
                
            }
            if(i==n-1) {
                int x=i-j+1;
                ans+=(long long)(x*(x+1))/2; 
            }
            
        }
        return ans;

        
    }
};
// @lc code=end

