class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
# method(2) 利用循环去查找子序列的头指针(内存小,速度慢)
#        start = 0
#        num = 0
#        for end, a in enumerate(s):
#            if(a not in s[start:end]):
#                if(end-start+1>num):
#                    num = end - start + 1
#            else:
#                while(s[start]!=a):
#                    start += 1
#                start += 1
#        return num
    
# method(2) 利用字典去查找子序列的头指针(内存大,速度快)
        start = 0
        num = 0
        dic = dict()
        for end, a in enumerate(s):
            if(a not in s[start:end]):
                dic[a] = end
                if(end-start+1>num):
                    num = end - start + 1
            else:
                start = dic[a] + 1
                dic[a] = end
        return num
        
