# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or k==0:
            return head
        
        p = head
        length = 1
        while p and p.next:
            p = p.next
            length += 1
        
        q = p
        q.next = head
        k = length - k%length
        p = head
        k -= 1
        while k:
            p = p.next
            k -= 1
        q = p.next
        p.next = None
        return q
        
        