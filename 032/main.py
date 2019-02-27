class Solution:
    def longestValidParentheses(self, s: str) -> int:
        num = [0]
        max_num = 0
        count = 0
        for ss in s:
            if ss == '(':
                count += 1
                if len(num) <= count:
                    num.append(0)
            elif ss == ')':
                if count>0:
                    count -= 1
                    num[count] += 1
                    if len(num) > count+1:
                        num[count] += num[count+1]
                        num[count+1] = 0
                else:
                    temp = max(num)*2
                    if max_num < temp:
                        max_num = temp
                    num = [0]
                    count = 0
        temp = max(num)*2
        if max_num < temp:
            max_num = temp
        return max_num

# other method
"""
        maxlen = 0
        stack = []
        start = -1
        for i, c in enumerate(s):
            if c == '(':
                stack.append(i)
            else:
                if stack:
                    stack.pop()
                    if stack:
                        l = i - stack[-1]
                    else:
                        l = i-start
                    if l > maxlen:
                        maxlen = l
                else:
                    start = i
        return maxlen
"""
