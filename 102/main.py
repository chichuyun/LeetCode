# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None: return []
        temp = [root]
        res = list()
        flag = 0
        for r in temp:
            if r.left or r.right:
                flag = 1
                break
            else:
                return [[root.val]]
        while(flag):
            flag = 0
            res.append([])
            temp_r = temp.copy()
            temp = list()
            for r in temp_r:
                flag = 1
                res[-1].append(r.val)
                if r.left:
                    temp.append(r.left)
                if r.right:
                    temp.append(r.right)
        if not res[-1]: del res[-1]
        return res
