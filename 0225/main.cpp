class MyStack {
private:
    queue<int> nums;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        nums.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num = nums.back();
        for(int i=0;i<nums.size()-1;++i) {
            nums.push(nums.front());
            nums.pop();
        }
        nums.pop();
        return num;
    }
    
    /** Get the top element. */
    int top() {
        return nums.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return nums.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */