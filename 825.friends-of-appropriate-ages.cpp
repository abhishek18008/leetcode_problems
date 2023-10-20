/*
 * @lc app=leetcode id=825 lang=cpp
 *
 * [825] Friends Of Appropriate Ages
 */

// @lc code=start
class Solution {
public:
    // given x---->y if request can be made
    bool ispossible(int x,int y){
        if(!(y<=0.5*x+7 ||  y>x || y>100 && x<100)){
            return true;
        }
        return false;
    }


    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int> mp;
        for(auto it:ages){
            mp[it]++;
        }

        int ans=0;
        for(auto a:mp){
            for(auto b:mp ){
                //find for at max 120 pairs and multiply them with the freq
                if(a.first!=b.first){
                    ans+=ispossible(a.first,b.first)*a.second*b.second;
                }
                else{
                    ans+=ispossible(a.first,b.first)*a.second*(a.second-1);
                }
                
            }
        }
        return ans;
    }
};
// @lc code=end

