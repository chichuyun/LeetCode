class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
# method(1) 速度极慢(优化了一部分, 尽量减少字符串赋值)
        if len(s) == 0: return s
        res = 0
        temp = 0
        temp_cen = 0
        max_len = 0
        max_temp = 0
        length = len(s)
        flag = 0
        for i, x in enumerate(s):
            if i + 1 < len(s) and x == s[i+1]:
                temp_cen = i
                left = i
                right = i + 1
                max_temp = 0
                while(left >= 0 and right < length):
                    if s[right] == s[left]:
                        max_temp += 2
                    else:
                        break
                    left -= 1
                    right += 1
            if max_len < max_temp:
                max_len = max_temp
                flag = 1
                max_temp = 0
                temp = temp_cen
            if i + 2 < len(s) and x == s[i+2]:
                temp_cen = i + 1
                left = i
                right = i + 2
                max_temp = 1
                while(left >= 0 and right < length):
                    if s[right] == s[left]:
                        max_temp += 2
                    else:
                        break
                    left -= 1
                    right += 1
            if max_len < max_temp:
                max_len = max_temp
                flag = 0
                max_temp = 0
                temp = temp_cen
        if flag == 0:
            return s[temp-max_len//2:temp+max_len//2+1]
        else:
            return s[temp-max_len//2+1:temp+max_len//2+1]
# method(2) 避免重复赋值
#        if len(s)<2 or s==s[::-1]:
#            return s
#        n = len(s)
#        start, maxlen = 0, 1
#        for i in range(n):
#            odd  = s[i-maxlen-1:i+1]  # len(odd) = maxlen + 2
#            even = s[i-maxlen:i+1]    # len(even)= maxlen + 1
#            if i-maxlen-1>=0 and odd==odd[::-1]:
#                start = i - maxlen - 1
#                maxlen += 2
#                continue
#            if i-maxlen>=0 and even==even[::-1]:
#                start = i - maxlen
#                maxlen += 1
#        return s[start:start+maxlen]
    
