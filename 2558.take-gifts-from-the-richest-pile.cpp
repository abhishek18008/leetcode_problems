/*
 * @lc app=leetcode id=2558 lang=cpp
 *
 * [2558] Take Gifts From the Richest Pile
 */

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }

        for(int i=0;i<k;i++){
            int took=pq.top();
            pq.pop();
            pq.push((sqrt(took)));
        }
        long long sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
        
    }
};
// @lc code=end

