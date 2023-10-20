/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int num) {
        if(num==0) return 1;
        int mask=1;
        while(num>mask){
            mask=mask*2+1;
        }
        return mask^num;
        
        
    }
};
// @lc code=end

