/*
 * @lc app=leetcode id=638 lang=cpp
 *
 * [638] Shopping Offers
 */

// @lc code=start
class Solution {
public:
    int n;
    int totaloffers;
    
    
    
    
    int solve(vector<int>& price, vector<vector<int>>& offers, vector<int>& needs, int idx) {
        // Base case
        if (idx == totaloffers) {
            // Just return the total corresponding to the left items
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += price[i] * needs[i];
            }
            return sum;
        }
        
        
        
        
        int mini = INT_MAX;
        
        // Don't choose this offer
        mini = min(solve(price, offers, needs, idx + 1), mini);
        
        // Choose this offer
        // Can choose this if any item doesn't exceed required
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (needs[i] - offers[idx][i] < 0) {
                flag = false;
            }
        }
        
        if (flag) {
            for (int i = 0; i < n; i++) {
                needs[i] -= offers[idx][i];
            }
            mini = min(solve(price, offers, needs, idx) + offers[idx][n], mini);
            for (int i = 0; i < n; i++) {
                needs[i] += offers[idx][i]; // Restore the state
            }
        }
        
        // Memoize the result
       
        
        return mini;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size();
        totaloffers = special.size();

        
        return solve(price, special, needs, 0);
    }
};

// @lc code=end

