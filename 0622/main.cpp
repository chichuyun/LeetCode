class MyCircularQueue {
private:
    int *data;
    int head=0, tail=0, len, now_len=0;
    int temp;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data = new int[k];
        len = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        data[tail] = value;
        temp = value;
        ++tail;
        if(tail==len) tail = 0;
        ++now_len;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        ++head;
        if(head==len) head = 0;
        --now_len;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) {
            return -1;
        } else {
            return data[head];  //head
        }
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) {
            return -1;
        } else {
            return temp;  //tail
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(now_len==0) {
            return true;
        } else {
            return false;
        }
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(now_len==len) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
