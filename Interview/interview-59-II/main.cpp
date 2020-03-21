class MaxQueue {
private:
    queue<int> nums;
    deque<int> maxs;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(nums.empty()) return -1;
        return maxs.front();
    }
    
    void push_back(int value) {
        while(!maxs.empty() && maxs.back()<value) {
            maxs.pop_back();
        }
        nums.push(value);
        maxs.push_back(value);
    }
    
    int pop_front() {
        if(nums.empty()) return -1;
        int res = nums.front();
        if(res==maxs.front()) {
            maxs.pop_front();
        }
        nums.pop();
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */