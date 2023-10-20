/*
 * @lc app=leetcode id=2683 lang=cpp
 *
 * [2683] Neighboring Bitwise XOR
 */

// @lc code=start
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        //tukka
        int x=0;
        for(auto it:derived){
            x^=it;
        }
        return x==0;
    }
};
// @lc code=end

