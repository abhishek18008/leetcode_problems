/*
 * @lc app=leetcode id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool ans=true;
        int last=-1;
        while(n){
            int bit=n%2;
            if(last!=-1 && bit==last)
            ans=false;
            last=bit;
            n=n/2;

        }
        return ans;
    }
};
// @lc code=end

