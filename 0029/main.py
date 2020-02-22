class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend==-2147483648 and divisor==-1:
            return 2147483647
        
        con1 = 1 if divisor>0 else -1
        divisor = divisor*con1
        con2 = 1 if dividend>0 else -1
        dividend = dividend*con2
        con = con1*con2
        
        res = 0
        while dividend >= divisor:
            c = 1
            temp = divisor
            while (temp << 1) < dividend:
                c <<= 1
                temp <<= 1
            res += c
            dividend -= temp

        return res*con
