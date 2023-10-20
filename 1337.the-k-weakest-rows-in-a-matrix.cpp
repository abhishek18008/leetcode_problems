/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution {
public:
    typedef pair<int,int> P;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<P,vector<P>,greater<P>> pq;
        int row=mat.size();
        int col=mat[0].size();
        for(int i=0;i<row;i++){
            int count=0;
            int l=0;
            int r=col;
            while(r>=l){
                int mid=(l+r)/2;
                if(mat[i][mid]==0)
                r=mid-1;
               else 
               l=mid+1;
            }
            count=l;
            pq.push({count,i});
        }
        vector<int> ans;

        for(int i=0;i<k;i++){
            auto p=pq.top();
            ans.push_back(p.second);
            pq.pop();
        }
        return ans;
        
    }
};
// @lc code=end

