/*
 * @lc app=leetcode id=2517 lang=cpp
 *
 * [2517] Maximum Tastiness of Candy Basket
 */

// @lc code=start
class Solution {
public:
    int n;
    bool ispossible(vector<int>& price, int k,int taste){
        int nums=1;
        int last=price[0];
        int i=1;
        while(i<n){
            if(price[i]-last>=taste){
                last=price[i];
                nums++;
            }
            i++;
        }
        if(nums>=k){
            return true;
        }
        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
         n=price.size();
         sort(price.begin(),price.end());

         int l=price[1]-price[0];
         int r=price[n-1]-price[0];

         while(l<r){
            int mid=(l+r+1)/2;
            if(!ispossible(price,k,mid)){
                r=mid-1;
            }
            else{
                l=mid;
            }
         }
         return l;
        
    }
};
// @lc code=end

