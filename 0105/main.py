# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """

        if not preorder:
            return None
        
        root = preorder[0]
        tree = TreeNode(root)
        index = inorder.index(root)
        tree.left = self.buildTree(preorder[1:index+1], inorder[:index])
        tree.right = self.buildTree(preorder[index+1:], inorder[index+1:])
        return tree
