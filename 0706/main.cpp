struct Node {
    int key, value;
    Node *next;
    Node(int x, int y) : key(x), value(y), next(nullptr) {}
};

class MyHashMap {
private:
    Node *nums[10001]={nullptr};
    Node *head=new Node(0,0), *p;
public:
    /** Initialize your data structure here. */
    MyHashMap() {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int k=key%10000;
        head->next = nums[k];
        p = head;
        while(p && p->next) {
            if(p->next->key==key) {
                p->next->value = value;
                return;
            }
            p = p->next;
        }
        p->next = new Node(key, value);
        nums[k] = head->next;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int k=key%10000;
        if(!nums[k]) {
            return -1;
        } else {
            p = nums[k];
            while(p) {
                if(p->key==key) {
                    return p->value;
                }
                p = p->next;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int k=key%10000;
        head->next = nums[k];
        p = head;
        while(p && p->next) {
            if(p->next->key==key) {
                Node *t=p->next;
                p->next = p->next->next;
                delete t;
            }
            p = p->next;
        }
        nums[k] = head->next;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */