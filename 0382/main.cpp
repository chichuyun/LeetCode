/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *h;
    default_random_engine e;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : h(head) {
    
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        
        int num, count = 0;
        ListNode *p = h;
        while(p) {
            uniform_int_distribution r(0, count);
            if(r(e) == 0) num = p->val;
            
            ++count;
            p = p->next;
        }
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */