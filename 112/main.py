# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
# method(1) 注意这里最终必须是叶子节点
        if root is None:
            return False
        else:
            return self.hasSum(root, sum)
    
    def hasSum(self, root, sum):
        sum -= root.val
        if not root.left and not root.right:
            if sum == 0:
                return True
            else:
                return False

        return (root.left is not None and self.hasSum(root.left, sum)) or \
               (root.right is not None and self.hasSum(root.right, sum))

# method(2) 简洁版
'''
    if root is None:
        return False
    return (root.val == sum and root.left is None and root.right is None) \
                              or self.hasPathSum(root.left, sum-root.val) or \
                                 self.hasPathSum(root.right, sum-root.val)
'''

