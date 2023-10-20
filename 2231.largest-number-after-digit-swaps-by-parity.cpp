/*
 * @lc app=leetcode id=2231 lang=cpp
 *
 * [2231] Largest Number After Digit Swaps by Parity
 */

// @lc code=start
class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<s.size();i++){
            if((s[i]-'0')%2==0)
            even.push_back(s[i]-'0');
            else
            odd.push_back(s[i]-'0');
        }
        int n=s.size();
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end(),greater<int>());
        int ans=0;
        int e=0;
        int o=0;
        for(int i=0;i<n;i++){
           if((s[i]-'0')%2)
           {
            ans+=odd[o]*pow(10,n-i-1);
            o++;
           }
           else 
           {
            ans+=even[e]*pow(10,n-i-1);
            e++;
           }

        }
        return ans;

        
    }
};
// @lc code=end

