# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
# method(1) 递归(似乎省内存)
        return not root or self.compare(root.left, root.right)
    
    def compare(self, left, right):
        if not left and not right:
            return True
        elif not left or not left:
            return False
        if left.val == right.val:
            return self.compare(left.left, right.right) and \
                   self.compare(left.right, right.left)
        return False
        
# method(2) 迭代
'''
        if root is None: return True
        if not root.left and not root.right:
            return True
        elif not root.left or not root.left:
            return False
        
        templ, tempr = [root.left], [root.right]
        while(templ or tempr):
            templ_r, tempr_r = templ.copy(), tempr.copy()
            templ.clear(); tempr.clear()
            for l, r in zip(templ_r, tempr_r):
                if l.val != r.val: return False
                if l.left and r.right:
                    templ.append(l.left)
                    tempr.append(r.right)
                elif l.left or r.right:
                    return False
                if l.right and r.left:
                    templ.append(l.right)
                    tempr.append(r.left)
                elif l.right or r.left:
                    return False
        return True
'''
