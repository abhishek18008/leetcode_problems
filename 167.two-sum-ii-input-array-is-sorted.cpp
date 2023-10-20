/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //using binary search
        int n=numbers.size();
        for(int i=0;i<n-1;i++){
            //find if target-numbers[i] exists in i+1 to n-1 range
            int l=i+1,r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(numbers[mid]>target-numbers[i]){
                    r=mid-1;
                }
                else if(numbers[mid]<target-numbers[i]){
                    l=mid+1;
                }
                else{
                    return {i+1,mid+1};
                }
            }
        }
        return {};

        
    }
};
// @lc code=end

