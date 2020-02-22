# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        p, q = head, head

        for _ in range(n):
            p = p.next

        if(p==None):
            return head.next

        while(p.next!=None):
            p, q = p.next, q.next

        q.next = q.next.next

        return head
