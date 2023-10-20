/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    int n;
    void solve(string& s,int idx){
        if(idx==n){
        ans.push_back(s);
        return ;
        }
        // if(isdigit(s[idx])){
        //     solve(s,idx+1);
        // }

        // else{
        //     //a character
        //     if(isupper(s[idx])){
        //         tolower(s[idx]);
        //         solve(s,idx+1);
        //         toupper(s[idx]);
        //     }
        // }

        
        if(isupper(s[idx])){
            s[idx]=tolower(s[idx]);
            solve(s,idx+1);
            s[idx]=toupper(s[idx]);
        }


        if(islower(s[idx])){
            s[idx]=toupper(s[idx]);
            solve(s,idx+1);
            s[idx]=tolower(s[idx]);
        }
        
        solve(s,idx+1);
        

    }
    vector<string> letterCasePermutation(string s) {
        n=s.size();
        solve(s,0);
        return ans;
        
    }
};
// @lc code=end

