/*
 * @lc app=leetcode id=813 lang=cpp
 *
 * [813] Largest Sum of Averages
 */

// @lc code=start
class Solution{
    public:
double largestSumOfAverages(vector<int>& A, int K) {
    int n=A.size();
    vector<vector<double>> dp(n, vector<double>(K+1, -1));
    return helper(A, 0, A.size(), K, dp);
    
}

double helper(vector<int> &A, int l, int n, int k, vector<vector<double>> &dp)
{
    
    if(l == n)
        return 0;
    
    if(dp[l][k] != -1)
        return dp[l][k];
    
    double sum = 0, res = 0;
    if(k==1 )
    {
        for(int i=l; i<n; i++)
            sum += A[i];
        return sum/(n-l);
    }

    double avg, temp;
    for(int i=l; i<n; i++)
    {
        sum += A[i];
        avg = sum/(i-l+1);
        temp = avg + helper(A, i+1, n, k-1, dp);z
        res = max(res, temp);
    }
    return  dp[l][k] = res;
}

};
// @lc code=end

