/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=1,r=n-2;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid-1] < arr[mid] && arr[mid]< arr[mid+1]){
                l=mid+1;
            }

            else if(arr[mid-1] > arr[mid] && arr[mid]> arr[mid+1]){
                r=mid-1;
            }

            else{
                return mid;
            }
        }
        return -1;

        
    }
};
// @lc code=end

