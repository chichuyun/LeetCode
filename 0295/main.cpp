class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> lefts;     // max heap
    priority_queue<int, vector<int>, greater<int>> rights; // min heap
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
    // lefts.size() >= rights.size()
        if(lefts.empty()) {
            lefts.push(num);
        } else if(lefts.size() > rights.size()) {
            if(num < lefts.top()) {
                rights.push(lefts.top());
                lefts.pop();
                lefts.push(num);
            } else {
                rights.push(num);
            }
        } else {
            if(num >= rights.top()) {
                lefts.push(rights.top());
                rights.pop();
                rights.push(num);
            } else {
                lefts.push(num);
            }
        }
    }
    
    double findMedian() {
        if(lefts.size() > rights.size()) {
            return lefts.top();
        } else {
            return ((double)lefts.top() + rights.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */