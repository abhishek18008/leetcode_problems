/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
 */

// @lc code=start
class Solution {
public:
    bool possible(string &s ,string &t,int maxCost,int req){
        int cost=0;
        int n=s.size();
        int len=0;
        int maxlen=0;
        int i=0;
       while(i<n){
            int temp=abs(s[i]-t[i]);
            if(cost+temp<=maxCost){
                len++;
                cost+=temp;
                i++;
            }
            else{
                len=0;
                cost=0;
            }
            maxlen=max(maxlen,len);
        }
        if(req<=maxlen)
        return true;
        return false;
    }


    int equalSubstring(string s, string t, int maxCost) {
        //binary search on maxlength
        // range is [0 length]
        // int len=s.size();
        // int l=0,r=len;
        // while(l<r){
        //     int mid=(l+r+1)/2;
        //     if(!possible(s,t,maxCost,mid)){
        //         r=mid-1;
        //     }
        //     else{
        //         l=mid;
        //     }
        // }
        // return  l;
        int cost=0;
        int n=s.size();
        
        int maxlen=0;
        int i=0,j=0;
        while(j<n){
            cost+=abs(s[j]-t[j]);
            if(cost<=maxCost){
                maxlen=max(maxlen,j-i+1);
                
            }
            else{
                while(cost>maxCost){
                    cost-=abs(s[i]-t[i]);
                    i++;
                }
            }
            j++;
           
        }
        return maxlen;
        
    }
};
// @lc code=end

