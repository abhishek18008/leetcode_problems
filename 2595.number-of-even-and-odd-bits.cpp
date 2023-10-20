/*
 * @lc app=leetcode id=2595 lang=cpp
 *
 * [2595] Number of Even and Odd Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int evencount=0;
        int oddcount=0;
        for(int i=0 ;i<32 ;i++){
            if((i&1)!=0 && (n&(1<<i))!=0)
            oddcount++;
            else if((i&1)==0 && (n&(1<<i))!=0)
            evencount++;
              
        }
        return{evencount,oddcount};
        
        

        
    }
};
// @lc code=end

