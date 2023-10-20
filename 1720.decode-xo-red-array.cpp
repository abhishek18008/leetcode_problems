/*
 * @lc app=leetcode id=1720 lang=cpp
 *
 * [1720] Decode XORed Array
 */

// @lc code=start
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size()+1;
        vector<int> ans(n);
        ans[0]=first;
        for(int i=1;i<n;i++){
            ans[i]=encoded[i-1]^ans[i-1];
        }
        return ans;
        
        
    }
};
// @lc code=end

