# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        con = 0
        head = ListNode(None)
        t = head

        p, q = l1, l2
        while (p is not None) or (q is not None):
            t1 = 0 if(p is None) else p.val
            t2 = 0 if(q is None) else q.val
            temp = t1 + t2 + con
            if temp >= 10:
                t.next = ListNode(temp-10)
                con = 1
            else:
                t.next = ListNode(temp)
                con = 0

            if p is not None: p = p.next
            if q is not None: q = q.next
            t = t.next

        if(con==1):
            t.next = ListNode(1)
        
        t = head
        head = head.next
        del t
        
        return head
