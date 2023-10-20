/*
 * @lc app=leetcode id=2070 lang=cpp
 *
 * [2070] Most Beautiful Item for Each Query
 */

// @lc code=start
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int,int>> querypair;
        for(int i=0;i<queries.size();i++){
            querypair.push_back({queries[i],i});
        }
        sort(querypair.begin(),querypair.end());
        sort(items.begin(),items.end());

        int n=queries.size();
        vector<int> ans(n);
        int itemidx=0;
        int maxbeauty=0;
        
        for(auto it:querypair){
            int maxprice=it.first;
            int originalidx=it.second;

            while(itemidx<items.size() && items[itemidx][0]<=maxprice){
                maxbeauty=max(maxbeauty,items[itemidx][1]);
                itemidx++;
            }
            ans[originalidx]=maxbeauty;
        }
        return ans;
        
    }
};
// @lc code=end

