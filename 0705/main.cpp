/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

class MyHashSet {
private:
    ListNode *nums[10001]={nullptr};
    ListNode *head=new ListNode(0), *p;
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }
    
    void add(int key) {
        int k=key%10000;
        head->next = nums[k];
        p = head;
        while(p && p->next) {
            if(p->next->val==key) {
                return;
            }
            p = p->next;
        }
        p->next = new ListNode(key);
        nums[k] = head->next;
    }
    
    void remove(int key) {
        int k=key%10000;
        head->next = nums[k];
        p = head;
        while(p && p->next) {
            if(p->next->val==key) {
                ListNode *t=p->next;
                p->next = p->next->next;
                delete t;
            }
            p = p->next;
        }
        nums[k] = head->next;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int k=key%10000;
        if(!nums[k]) {
            return false;
        } else {
            p = nums[k];
            while(p) {
                if(p->val==key) {
                    return true;
                }
                p = p->next;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */