/*
 * @lc app=leetcode id=2260 lang=cpp
 *
 * [2260] Minimum Consecutive Cards to Pick Up
 */

// @lc code=start
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        int i=0,j=0;
        int mincard=INT_MAX;
        unordered_map<int,int> mp;
        while(j<n){
            mp[cards[j]]++;
            while(j-i+1>mp.size()){
                mincard=min(mincard,j-i+1);
                mp[cards[i]]--;
                if(mp[cards[i]]==0){
                    mp.erase(cards[i]);
                }
                i++;
            }
            j++;
        }
        return mincard==INT_MAX ? -1:mincard; 
        
    }
};
// @lc code=end

