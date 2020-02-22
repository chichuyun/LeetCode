# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
# method(1) 啰嗦了一些
        return self.isValid(root, None, None)
    
    def isValid(self, root, left, right):
        if not root:
            return True
        
        if (left is not None and root.val <= left) or \
          (right is not None and root.val >= right):
            return False
        
        flag = True
        if root.left:
            flag = flag and self.isValid(root.left, left, root.val)

        if root.right:
            flag = flag and self.isValid(root.right, root.val, right)

        return flag
# method(2) 简洁一些但等价的解法
'''
        return self.isValidBSTRecu(root, float("-inf"), float("inf"))
    
    def isValidBSTRecu(self, root, low, high):
        if root is None:
            return True
        
        return low < root.val < high \
            and self.isValidBSTRecu(root.left, low, root.val) \
            and self.isValidBSTRecu(root.right, root.val, high)
'''
