class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows<=1: return s
        temp = ''
        length = 2*numRows - 2
        
        for row in range(numRows):
            if row == numRows - 1 or row == 0:
                temp += s[row::length]
            else:
                flag = 0
                i = row
                while(i<len(s)):
                    temp += s[i]
                    if flag == 0:
                        i += (numRows - row)*2 - 2
                        flag = 1
                    else:
                        i += 2*row
                        flag = 0
        return temp
