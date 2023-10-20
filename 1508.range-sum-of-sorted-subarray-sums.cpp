/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
class Solution {
public:
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> permuts;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                permuts.push_back(sum);
            }
        }
        sort(permuts.begin(),permuts.end());
        
        
        long long res = accumulate(permuts.begin() + left - 1, permuts.begin() + right, 0LL) % 1000000007;
	return res;
    }
};
// @lc code=end

