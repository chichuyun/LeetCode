# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        
        tree, res = [root], list()
        i = 1
        while(len(tree)):
            temp = tree.copy()
            tree.clear()
            res.append([])
            for node in temp[::-1]:
                res[-1].append(node.val)
                if i%2 == 1:
                    if node.left: tree.append(node.left)
                    if node.right: tree.append(node.right)
                else:
                    if node.right: tree.append(node.right)
                    if node.left: tree.append(node.left)
            i += 1
        return res
            
