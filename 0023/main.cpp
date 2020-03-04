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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        return mergeSub(lists, 0, lists.size()-1);
    }

    ListNode* mergeSub(vector<ListNode*>& lists, int left, int right) {
        int mid=(left+right)/2;
        if(right==left) {
            return lists[left];
        } else if(right==left+1) {
            return mergeTwo(lists[left], lists[right]);
        } else {
            ListNode *q = mergeSub(lists, left, mid);
            ListNode *p = mergeSub(lists, mid+1, right);
            return mergeTwo(p, q);
        }
        return nullptr;
    }

    ListNode* mergeTwo(ListNode* p, ListNode *q) {
        ListNode *head=new ListNode(0), *k=head;
        
        while(p && q) {
            if(p->val<=q->val) {
                k->next = p;
                p = p->next;
            } else {
                k->next = q;
                q = q->next;
            }
            k = k->next;
        }
        if(!p) {
            k->next = q;
        } else {
            k->next = p;
        }
        return head->next;
    }
};