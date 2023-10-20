/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution {
public:
    int minFlips(int a, int b, int c) {
       int ans=0;
       while( a || b || c)  //it process untill all digits become zero
       {
           //extracting all LSBs of a , b and c
           //we can extract LSB by performing '&' operation to 1

            int x1 = a & 1;
            int x2 = b & 1;
            int x3 = c & 1;
            
            if( (x1 | x2) != x3)  //if this true then we have to flip the digits according to question
            {
               if(x1&x2) ans += 2;   //if both are 1 then we have to flip 2 times
               else      ans += 1;   //else only 1 times
            }

            //shift to right by 1 position to perform operation in next digits 
            a = a>>1;       
            b = b>>1;
            c = c>>1; 
       } 
       return ans;
    }
};

// @lc code=end

