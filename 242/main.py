class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
# method(1) 排序，但是没必要
        if sorted(s) == sorted(t):
            return True
        else:
            return False
# method(2) 这里只需要字母数相同
'''
        from collections import Counter
        return Counter(s) == Counter(t)
'''
