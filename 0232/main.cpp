class MyQueue {
private:
    stack<int> nums;
    stack<int> temp;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        nums.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int len=nums.size()-1;
        for(int i=0;i<len;++i) {
            temp.push(nums.top());
            nums.pop();
        }
        int num=nums.top();
        nums.pop();
        for(int i=0;i<len;++i) {
            nums.push(temp.top());
            temp.pop();
        }
        return num;
    }
    
    /** Get the front element. */
    int peek() {
        int len=nums.size()-1;
        for(int i=0;i<len;++i) {
            temp.push(nums.top());
            nums.pop();
        }
        int num=nums.top();
        for(int i=0;i<len;++i) {
            nums.push(temp.top());
            temp.pop();
        }
        return num;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return nums.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */