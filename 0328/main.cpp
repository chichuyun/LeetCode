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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even, *odd, *p=head, *cen;
        int length=0;
// 读取列表的长度
        while(p) {
            length++;
            p = p->next;
        }
// 长度小于2直接输出
        if(length<=2)
            return head;

        p = head;         // node 1
        even = p->next;   // node 2
        odd = even->next; // node 3

        p->next = odd;
        even->next = odd->next;
        odd->next = even;
        cen = even;       // 保存偶列表的head
        for(int i=0;i<length/2+length%2-2;i++) {
            p = p->next;
            even = even->next;
            odd = even->next;
            
            p->next = odd;
            even->next = odd->next;
            odd->next = cen;
        }
        return head;
    }
};
