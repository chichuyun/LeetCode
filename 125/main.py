class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
# method(1) 一个一个对比
        i = 0
        j = len(s) - 1
        while(i <= j):
            if not s[i].isalnum():
                i += 1
                continue
            if not s[j].isalnum():
                j -= 1
                continue
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
        return True
# method(2) 整体比较
'''
        s = s.lower()
        character = 'abcdefghijklmnopqrstuvwxyz0123456789'
        l = []
        for i in s:
            if i in character:
                l.append(i)
        if l == l[::-1]:
            return True
        return False
'''
