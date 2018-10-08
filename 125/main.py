class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
# method(1) 一个一个对比
        ascii_set = set(list(range(ord('0'),ord('9')+1)) + \
                        list(range(ord('a'),ord('z')+1)))
        
        s = s.lower()
        i = 0
        j = len(s) - 1
        while(i <= j):
            if ord(s[i]) not in ascii_set:
                i += 1
                continue
            if ord(s[j]) not in ascii_set:
                j -= 1
                continue
            if s[i] != s[j]:
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
