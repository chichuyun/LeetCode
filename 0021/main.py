# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        elif not l2:
            return l1
        
        head = ListNode(0)
        p1, p2 = l1, l2
        if p1.val <= p2.val:
            head.next = p1
            p1 = p1.next
        else:
            head.next = p2
            p2 = p2.next
        p = head
        p = p.next
        
        while p1 and p2:
            if p1.val <= p2.val:
                p.next = p1
                p1 = p1.next
            else:
                p.next = p2
                p2 = p2.next
            p = p.next
            
        if p1:
            p.next = p1
        else:
            p.next = p2
        
        return head.next