/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
public:
    int k;
    vector<int> nums;
    KthLargest(int k, vector<int>& v) {
        this->k=k;
        for(auto it: v){
            nums.push_back(it);
        }
        make_heap(nums.begin(),nums.end());
        
    }
    
    int add(int val) {
        nums.push_back(val);
        push_heap(nums.begin(),nums.end());
        int ans;
        for(int i=0;i<k;i++){
            pop_heap(nums.begin(),nums.end());
            ans=nums[nums.size()-1];
            nums.pop_back();
        }
        return ans;
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

