class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        s = str.strip().split()
        if s == []: return 0
        s = s[0]
        temp = ''
        flag = 0
        for i, x in enumerate(s):
            if i == 0 and (x == '+' or x == '-'):
                temp += x
            elif ord(x) in list(range(48,58)):
                temp += x
                flag = 1
            else:
                break
        if flag == 0: return 0
        if int(temp) > 2**31-1:
            return 2**31-1
        elif int(temp) < -2**31:
            return -2**31
        else:
            return int(temp)
