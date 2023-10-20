/*
 * @lc app=leetcode id=1734 lang=cpp
 *
 * [1734] Decode XORed Permutation
 */

// @lc code=start
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size();
        //first find the first element of the permutation
        int x=0;
        for(int i=1;i<=n+1;i++){
            x^=i;
        }

        //xor this with odd indexed elements
        for(int i=1;i<n;i+=2){
            x^=encoded[i];
        }

        //x now contains the first element of the decoded permutation
        vector<int> ans(n+1);
        ans[0]=x;
        for(int i=1;i<=n;i++){
            ans[i]=ans[i-1]^encoded[i-1];
        }
        return ans;
    }
};
// @lc code=end

