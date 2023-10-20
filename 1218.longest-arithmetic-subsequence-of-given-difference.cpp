/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

// @lc code=start
class Solution {
public:
    int n,D;
    int solve(vector<int>& arr,int idx){
        int res=0;
        for(int i=idx+1;i<n;i++){
            int prev=arr[idx];
            int curr=arr[i];

            if(curr-prev==D){
                res=max(res,1+solve(arr,i));
            }

        }
        return res;
    }


    int longestSubsequence(vector<int>& arr, int difference) {
         n=arr.size();
         D=difference;
        //consider from i =0 to n-1 as first element in our sequence
        int maxi=0;
        for(int i=0;i<n;i++){
            //i will already be selected
            maxi=max(maxi,solve(arr,i)+1);
        }
        return maxi;
        
    }
};
// @lc code=end

