class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1 || nums.empty()) return nums;
        
        vector<int> res;
        deque<int> maxs;
        for(int i=0;i<k;++i) {
            while(!maxs.empty() && nums[i]>maxs.back()) maxs.pop_back();
            maxs.push_back(nums[i]);
        }
        
        int last;
        res.push_back(maxs.front());
        for(int i=k;i<nums.size();++i) {
            last = nums[i-k];
            if(maxs.front()==last) maxs.pop_front();
            while(!maxs.empty() && nums[i]>maxs.back()) maxs.pop_back();
            maxs.push_back(nums[i]);
            res.push_back(maxs.front());
        }
        return res;
    }
};