/*
 * @lc app=leetcode id=1297 lang=cpp
 *
 * [1297] Maximum Number of Occurrences of a Substring
 */

// @lc code=start
class Solution {
public:
    int givelen(string &s,int maxLetters,int k){
        int n=s.size();
        //check highest repeating substring of length k
        unordered_map<int,int> freqmap;
        unordered_map<string,int> maxoccur;
        int i=0,j=0;
        while(j<n){
            freqmap[s[j]]++;
            
            if(j-i+1>k){
                freqmap[s[i]]--;
                if(freqmap[s[i]]==0) 
                freqmap.erase(s[i]);
                i++;
            }
            if(j-i+1==k && freqmap.size()<=maxLetters){
                maxoccur[s.substr(i,k)]++;
            }
            j++;
        }
        int ans=0;
        for(auto it:maxoccur){
            cout<<it.first<<" --->"<<it.second<<endl;
            ans=max(ans,it.second);
        }
        return ans;
    }



    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        //brute force 
        int n=s.size();
        int maxi=0;
        for(int i=minSize;i<=minSize;i++){
            //check highest val for each size substring
            maxi=max(maxi,givelen(s,maxLetters,i));

        }
        return maxi;
    }
};
// @lc code=end

