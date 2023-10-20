/*
 * @lc app=leetcode id=1870 lang=cpp
 *
 * [1870] Minimum Speed to Arrive on Time
 */

// @lc code=start
class Solution {
public:
    bool canreach(vector<int>& dist,int speed,double hour){
        int n=dist.size();
        double time=0.0;
        for(int i=0;i<n-1;i++){
            time+=(dist[i]+speed-1/speed);
        }
        time+=(double)dist[n-1]/speed;
        if(time<=hour) return true;
        return false;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(hour<=n-1) return -1;
        int l=1,r=1e8;

        while(l<r){
            int mid=(l+r)/2;
            if(!canreach(dist,mid,hour)){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
        
    }
};
// @lc code=end

