/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class MyLinkedList {
private:
    ListNode *head=nullptr;
    int length=0;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {}

    /** Get the value of the index-th node in the linked list.
     If the index is invalid, return -1. */
    int get(int index) {
        ListNode *p=head;

        if(index>=length || index<0) return -1;

        for(int i=0;i<index;i++) p = p->next;
        return p->val;
    }

    /** Add a node of value val before the first element of the linked list.
    After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *q=new ListNode(val);

        q->next = head;
        head = q;
        length++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *p=head, *q=new ListNode(val);

        while(p->next!=nullptr) p = p->next;
        p->next = q;
        length++;
    }

    /** Add a node of value val before the index-th node in the linked list.
    If index equals to the length of linked list, the node will be appended
    to the end of linked list. If index is greater than the length,
    the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode *p=head, *q=new ListNode(val);

        if(index>length) {
            return;
        } else if(index==0) {
            addAtHead(val);
            return;
        } else if(index==length) {
            addAtTail(val);
            return;
        }

        for(int i=1;i<index;i++) p = p->next;
        q->next = p->next;
        p->next = q;
        length++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode *p=head, *q;

        if(index>=length || index<0) {
            return;
        } else if(index==0) {
            q = head;
            head = q->next;
            delete q;
            return;
        }

        for(int i=1;i<index;i++) p = p->next;
        q = p->next;
        p->next = q->next;
        delete q;
        length--;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
