class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        num = 0
        dic1 = {'I':1,'V':5,'X':10,'L':50,\
               'C':100,'D':500,'M':1000}
        dic2 = {'IV':2,'IX':2,'XL':20,'XC':20,'CD':200,'CM':200}
        for roman, n in dic1.items():
            num += s.count(roman)*n
        for roman, n in dic2.items():
            if roman in s:
                num -= n
        return num
