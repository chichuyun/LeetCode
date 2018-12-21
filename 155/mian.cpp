class MinStack {
private:
    stack<int> s;
    int min;

public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty()) {
            min = x;
        } else if(min > x) {
            min = x;
        }
        s.push(min);
        s.push(x);
    }
    
    void pop() {
        if(!s.empty()) {
            s.pop();
            s.pop();
        }
        if(!s.empty()) {
            int x = s.top();
            s.pop();
            min = s.top();
            s.push(x);
        }
    }
    
    int top() {
        if(!s.empty())
            return s.top();
    }
    
    int getMin() {
        if(!s.empty())
            return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
