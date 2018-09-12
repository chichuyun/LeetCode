class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
# method(1)双指针,两头同时对比,对比一半
        str_x = str(x)
        for i in range(len(str_x)//2):
            if(str_x[i]!=str_x[-i-1]): return False
        return True

# method(2)倒序和逆序相等,这里比较的是倒序和逆序的整数,这要比比较字符串快
#        if x < 0:
#            return False
#        return int(str(x)[::-1]) == x
