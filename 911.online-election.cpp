/*
 * @lc app=leetcode id=911 lang=cpp
 *
 * [911] Online Election
 */

// @lc code=start
class TopVotedCandidate {
public:
    vector<int> times;
    //maintain an array for the leading person at time t
    unordered_map<int,int> winner;
    //winner[t=15] => tom
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times=times;
        int n=persons.size();
        vector<int> votecount(n,0);
        int maxvotestillnow=0;
        for(int i=0;i<n;i++){
            votecount[persons[i]]++;
            if(votecount[persons[i]]>=maxvotestillnow){
                winner[times[i]]=persons[i];
                maxvotestillnow=votecount[persons[i]];
            }
            else{
                winner[times[i]]=winner[times[i-1]];
            }

        }  
    }
    
    int q(int t) {
        //do a binary serach on times to find time equal to or less than t;
        int n=times.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r+1)/2;
            if(times[mid]<=t){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        return winner[times[l]];
   
    }

};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

