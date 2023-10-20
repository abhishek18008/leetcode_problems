/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
public:
    unordered_map<string,vector<int>> mp;
    bool ispurenumber(string s){
        for(int i=0;i<s.size();i++){
            if(!isdigit(s[i]))
            return false;
        }
        return true;
    }


    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        int n=expression.size();
        //base case
        if(mp.find(expression)!=mp.end())
        return mp[expression];
        if(ispurenumber(expression)){
            res.push_back(stoi(expression));
        }

        for(int i=0;i<n;i++){
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
                vector<int> left=diffWaysToCompute(expression.substr(0,i));
                vector<int> right=diffWaysToCompute(expression.substr(i+1));

                for(int j=0;j<left.size();j++){
                    for(int k=0;k<right.size();k++){

                        if(expression[i]=='*')
                        res.push_back(left[j]*right[k]);

                        else if(expression[i]=='+')
                        res.push_back(left[j]+right[k]);

                        else
                        res.push_back(left[j]-right[k]);
                    }
                }

            }
        }
        return mp[expression]=res;

        
    }
};
// @lc code=end

