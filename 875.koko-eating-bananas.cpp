/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
   int minEatingSpeed(vector<int>& piles, int h) {
        long long right=*max_element(piles.begin(),piles.end());
        long long left=1;
        while(left<=right){
            long long mid=(right+left)/2;
            long long hoursrequired=0;
            for(long long i=0;i<piles.size();i++){
                long long x=piles[i]%mid;
                if(x){
                    hoursrequired+=piles[i]/mid+1;
                }
                else{
                    hoursrequired+=piles[i]/mid;
                }
            }
                if(hoursrequired>h){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            
        }
        return left;
        
    }
};
// @lc code=end

