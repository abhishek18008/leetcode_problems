/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int n=arr.size();
       int l=0,r=n-1;
       while(l<r){
        int mid=(l+r)/2;
        if(arr[mid]<x){
            l=mid+1;
        }
        else{
            r=mid;
        }
       }
       // expand this to fit in k integers
       int i=l-1,

       

    }
};
// @lc code=end

