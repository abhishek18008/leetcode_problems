/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

// @lc code=start
class Solution {
public:
    

    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int numones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')
            numones++;
            prefix[i]=numones;
        }

        int numzeros=0;
        for(int i=n-1;i>=0;--i){
            
            if(s[i]=='0')
            numzeros++;
        suffix[i]=numzeros;
            
            
        }

        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            ans=min(ans,prefix[i]+suffix[i+1]);
        }
        
        ans=min(ans,suffix[0]);
        ans=min(ans,prefix[n-1]);
        return ans;




    }
};

// @lc code=end

