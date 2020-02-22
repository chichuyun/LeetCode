/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *p=head, *q=nullptr, *h=head;
// 读取长度
        int length=0;
        while(p) {
            length++;
            p = p->next;
        }
        if(length<=1)
            return true;
// 达到列表中央
        p = head;
        for(int i=0;i<length/2;i++)
            p = p->next;
// 翻转列表,q为翻转后的结果
        while(p) {
            ListNode *t=new ListNode(p->val);
            t->next = q;
            q = t;
            p = p->next;
        }
// 对比链表(一个从头,一个从中间)
        for(int i=0;i<length/2;i++) {
            if(h->val!=q->val)
                return false;
            h = h->next;
            q = q->next;
        }
        return true;
    }
};
