/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        //track all the strings using the bit mask
        vector<int> mask(n,0);
        for(int i=0;i<n;i++){
            for(auto it: words[i]){
                //set the bit corresponding to that letter
                int k=it-'a';
                mask[i]|=(1<<k);
            }
        }

        //use n^2 to find out max product
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((mask[i] & mask[j])==0){
                    int temp=(words[i].size()*(words[j]).size());
                    maxi=max(maxi,temp);
                }
            }
        }
        return maxi;

        
    }
};
// @lc code=end

