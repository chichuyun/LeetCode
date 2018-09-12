class Solution:
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
# method(1) 笨方法
#        left = 0
#        right = 0
#        s = list(s)
#        for i, x in enumerate(s):
#            if x == ' ':
#                right = i
#                s[left:right] = s[left:right][::-1]
#                left = i + 1
#        s[left:len(s)] = s[left:len(s)][::-1]
#        return ''.join(s)
# method(2) 直接将结果输出
        return ' '.join([sub[::-1] for sub in s.split()])     
