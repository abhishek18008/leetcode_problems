/*
 * @lc app=leetcode id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& books,int idx,int widthleft,int maxshelfheight,int shelfWidth){
        //base case
        // if(widthleft<0) return INT_MAX;
        if(idx==books.size()) return maxshelfheight;
        if(dp[idx][widthleft]!=-1) return dp[idx][widthleft];

        int sameshelf=INT_MAX,nextshelf=INT_MAX;
        int currwidth=books[idx][0];
        int currheight=books[idx][1];
        if(widthleft>=currwidth){
            sameshelf=solve(books,idx+1,widthleft-currwidth,max(maxshelfheight,currheight),shelfWidth);
        }

        nextshelf=maxshelfheight+solve(books,idx+1,shelfWidth-currwidth,currheight,shelfWidth);
        return dp[idx][widthleft]=min(sameshelf,nextshelf);

    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        dp.resize(n+1,vector<int>(shelfWidth+1,-1));
        return solve(books,0,shelfWidth,0,shelfWidth);
        
    }
};
// @lc code=end

