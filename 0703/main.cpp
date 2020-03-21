class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> sets; // min heap
//    priority_queue<int> sets; // max heap
    int count;
public:
    KthLargest(int k, vector<int>& nums) {
        count = k;
        for(int i=0;i<nums.size();++i) {
            if(count > i) {
                sets.push(nums[i]);
            } else {
                if(sets.top()<nums[i]) {
                    sets.pop();
                    sets.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(sets.size()<count) {
            sets.push(val);
        } else if(sets.top()<val) {
            sets.pop();
            sets.push(val);
        }
        return sets.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */