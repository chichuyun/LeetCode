# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if not root:
            return TreeNode(val)
        
        self.insert(root, val)
        return root
    
    def insert(self, root, val):
        if root.val < val:
            if root.right:
                self.insert(root.right, val)
            else:
                root.right = TreeNode(val)
        else:
            if root.left:
                self.insert(root.left, val)
            else:
                root.left = TreeNode(val)
            
