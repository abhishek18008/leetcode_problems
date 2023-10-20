/*
 * @lc app=leetcode id=1947 lang=cpp
 *
 * [1947] Maximum Compatibility Score Sum
 */

// @lc code=start
class Solution {
public: 
    int match(vector<int> &a,vector<int>& b){
        int n=a.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[i])
            count++;
        }
        return count;
    }

    int solve(vector<vector<int>>& students,vector<vector<int>>& mentors,vector<int>& used,int idx){
        int n=students.size();
        if(idx==n) return 0;

        int ans=0;
        //try assigning any of the available mentors to student at idx and maximize the result
        for(int i=0;i<n;i++){
            if(used[i]==0){
                used[i]=1;
                ans=max(ans,solve(students,mentors,used,idx+1)+match(students[idx],mentors[i]));
                used[i]=0;
            }
        }
        return ans;

    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size();
        vector<int> used(n,0);
        return solve(students,mentors,used,0);

        
    }
};
// @lc code=end

