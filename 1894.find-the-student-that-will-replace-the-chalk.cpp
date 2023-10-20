/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long sum=accumulate(chalk.begin(),chalk.end(),0l);
        
        k=k%sum;
        int i=0;
        while(true){
            k-=chalk[i];
            if(k<0) return i;
            i++;
        }
        return -1;
        
    }
};
// @lc code=end

