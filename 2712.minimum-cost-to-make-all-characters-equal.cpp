/*
 * @lc app=leetcode id=2712 lang=cpp
 *
 * [2712] Minimum Cost to Make All Characters Equal
 */

// @lc code=start
class Solution {
public:
    long long minimumCost(string s) {
        long long n=s.size();
        vector<long long> prefix(n,0);
        vector<long long> suffix(n,0);
        for(long long i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                prefix[i]=prefix[i-1]+i;
            }
            else{
                prefix[i]=prefix[i-1];
            }
        }
        

        for(long long i=n-2;i>=0;--i){
            if(s[i]!=s[i+1]){
                suffix[i]=suffix[i+1]+(n-i-1);
            }
            else{
                suffix[i]=suffix[i+1];
            }
        }
        
        long long mini=1e18;
        for(long long i=0;i<n;i++){
            mini=min(mini,prefix[i]+suffix[i]);
        }
        return mini;
    }
};
// @lc code=end

