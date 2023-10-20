/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int bitcount=0;
            for(int j=0 ; j<32 ; j++){
                if((arr[i]& (1<<j))!=0)
                bitcount++;  
            }
            v.push_back({bitcount,arr[i]});
            
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i].second);
        }
        return ans;
        
    }
};
// @lc code=end

