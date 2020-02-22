# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        
        if not postorder:
            return None
        
        root = postorder[-1]
        tree = TreeNode(root)
        index = inorder.index(root)
        tree.left = self.buildTree(inorder[:index], postorder[:index])
        tree.right = self.buildTree(inorder[index+1:], postorder[index:-1])
        return tree
