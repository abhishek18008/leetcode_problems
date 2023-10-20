/*
 * @lc app=leetcode id=2379 lang=cpp
 *
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks
 */

// @lc code=start
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int i=0;
        int j=0;
        int blacks=0;
        int ans=INT_MAX;
        while(j<n){
            if(blocks[j]=='B')
            blacks++;
            if(j-i+1!=k){
                j++;
            }
            else{
                int topaint=k-blacks;
                ans=min(ans,topaint);
                if(blocks[i]=='B')
                blacks--;
                i++;
                j++;
            }
        }
        return ans;
        
    }
};
// @lc code=end

