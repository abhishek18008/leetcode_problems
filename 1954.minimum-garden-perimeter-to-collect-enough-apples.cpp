/*
 * @lc app=leetcode id=1954 lang=cpp
 *
 * [1954] Minimum Garden Perimeter to Collect Enough Apples
 */

// @lc code=start
class Solution {
public:
    long long int minimumPerimeter(long long int neededApples) {
        long long int sum=0;
        long long int i=1;
        long long int peri=0;
        while(true){
          long long temp=12*i*i;
          sum+=temp;
          if(sum<neededApples){
            i++;
          }
          else{
            peri= 8*i;
            break;
          }
        }
        return peri;
        
    }
};
// @lc code=end

