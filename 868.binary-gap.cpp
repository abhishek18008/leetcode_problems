/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

// @lc code=start
class Solution {
public:
    int binaryGap(int n) {
        int maxi=0;
        int last=-1;
        for(int i=0;i<31;i++){
            if((n&(1<<i)) !=0 ){
                if(last!=-1)
                maxi=max(maxi,i-last);
                last=i;
            }
        }
        return maxi;
    }
};
// @lc code=end

