/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start

//brute force
class MyCalendar {
public:
    vector<pair<int,int>> bookings;

    bool book(int start, int end) {
        bool flag=true;
        for(auto it:bookings){
            if(!(start>=it.second || end<=it.first)){
                flag=false;
            }
        }
        if(flag){
            bookings.push_back({start,end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

