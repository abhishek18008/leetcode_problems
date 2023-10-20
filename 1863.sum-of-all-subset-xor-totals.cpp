/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution {
public:
    // int subsetXORSum(vector<int>& nums) {
    //     int n=nums.size();
    //     int ans=0;
    //     for(int i=1 ; i<(1<<n) ; i++){
    //         int idt=0;
    //         for(int j=0 ; j<n ; j++){
    //             if((i & (1<<j))!=0)
    //             {
    //                 idt=idt^nums[j];
    //             }
                    
    //         }
    //         ans+=idt;
              
    //     }
    //     return ans;
        
        
    // }

   void solve(vector<int>& nums,int & ans,int currans,int index){
        int n=nums.size();
        if(index==n){
            ans+=currans;
          return ;
        }

        //considering current index element in the subset
   
        solve(nums,ans,currans^nums[index],index+1);


        //don't consider 
        solve(nums,ans,currans,index+1);

        return;
    }

    int subsetXORSum(vector<int>& nums){
        int ans=0;
        int currans=0;
        solve(nums,ans,currans,0);
        return ans;


    }
//kahan taqleef de raha hai
//kahan taqleef de raha hai
};
// @lc code=end

