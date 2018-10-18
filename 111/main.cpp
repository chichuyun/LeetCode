# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
# method(1) 层次遍历的方法
        if not root:
            return 0
        
        temp = [root]
        counts = 0
        while(True):
            counts += 1
            nodes = list()
            for node in temp:
                if not node.left and not node.right:
                    return counts
                if node.left: nodes.append(node.left)
                if node.right: nodes.append(node.right)
            temp = nodes.copy()
            
# method(2) 递归
'''
        if not root:
            return 0
        elif root.left and root.right:
            return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
        else:
            return max(self.minDepth(root.left), self.minDepth(root.right)) + 1
'''
