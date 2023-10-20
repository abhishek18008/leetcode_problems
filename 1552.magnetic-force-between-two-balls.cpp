/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution {
public:
    bool ispossible(vector<int>& position,int m,int force){
        int n=position.size();
        int ball=1;
        int lastpos=position[0];
        for(int i=1;i<n;i++){
            int dist=position[i]-lastpos;
            if(dist>=force){
                ball++;
                lastpos=position[i];
            }
        }
        if(ball>=m){
            return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        //binary serach on answer
        int n=position.size();
        sort(position.begin(),position.end());
        int l=1;
        int r=position[n-1]-position[0];
        while(l<r){
            int mid=l+(r-l+1)/2;
            if(!ispossible(position,m,mid)){
                r=mid-1;
            }
            else{
                l=mid;
            }

        }
        return l;
        
    }
};
// @lc code=end

