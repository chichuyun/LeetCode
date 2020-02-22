class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        Lis = ['M','D','C','L','X','V','I']
        dic1 = {'M':1000,'D':500,'C':100,'L':50,'X':10,'V':5,'I':1}
        dic2 = {'M':100,'D':100,'C':10,'L':10,'X':1,'V':1,'I':0}
        dic3 = {'M':'CM','D':'CD','C':'XC','L':'XL','X':'IX','V':'IV'}

        s = ''
        for string in Lis:
            n = dic1[string]
            div = num//n
            if div>=1:
                s += div*string
                num -= div*n
            if num + dic2[string] >= n:
                s += dic3[string]
                num -= n - dic2[string]
        return s
