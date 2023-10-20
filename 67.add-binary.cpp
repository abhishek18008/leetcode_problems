/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(begin(a),end(a));
        reverse(begin(b),end(b));
        string ans="";
        int n=a.size();
        int m=b.size();
        int loop=min(n,m);
        int carry=0;
        //run a loop till the min len of both
        int i;
        for( i=0;i<loop;i++ ){
            int temp=a[i]-'0'+b[i]-'0'+carry;
            if(temp>1) {
                temp=temp-2;
                carry=1;
            }
            ans+=to_string(temp);
        }
        // if string a is still remaining
       
            while(i<n){
                int temp=a[i]-'0'+carry;
            if(temp>1) {
                temp=temp-2;
                carry=1;
            }
            ans+=to_string(temp); 
            i++;
            } 
            
            while(i<m){
                int temp=a[i]-'0'+carry;
            if(temp>1) {
                temp=temp-2;
                carry=1;
            }
            ans+=to_string(temp); 
            i++;
            } 
        
        if(carry==1) ans.push_back('1');
        reverse(begin(ans),end(ans));
        return ans;
    }
};
// @lc code=end

