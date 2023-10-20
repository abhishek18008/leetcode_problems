class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int> mp;
        for(auto it:banned){
            mp[it]=1;
        }
        int sum=0;
        int i=1;
        int count=0;
        while(i<=n){
            if(mp.count(i)==0 && i<=maxSum-sum){
                sum+=i;
                count++;
            }
            if(sum>maxSum){
                break;
            }
            i++;
        }
        return count;
    }
};