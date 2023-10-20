/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> solve(int x,int y,int n){
        if(2*n-(x+y)==1)
        {
            return {")"};
        }

        vector<string> ans;
        vector<string> left;
        vector<string> right;
        if(x<n)
        {
             left=solve(x+1,y,n);
        }
        if(y<x)
        {
            right=solve(x,y+1,n);
        }
        for(int i = 0; i < left.size(); i++)
        {
            ans.push_back("("+left[i]);
        }

        
        for(int i = 0; i < right.size(); i++)
        {
            ans.push_back(")"+right[i]);
        }
        return ans;
        
    }


    vector<string> generateParenthesis(int n) {
       return  solve(0,0,n);
        
    }
};
// @lc code=end

