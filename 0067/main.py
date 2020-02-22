class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
# method(1) 最一般的方法
        c = ''
        con = 0
        len_a = len(a)
        len_b = len(b)
        
        for i in range(1,max(len(a),len(b))+1):
            a0 = a[-i] if(i<=len_a) else 0
            b0 = b[-i] if(i<=len_b) else 0
            c0 = int(a0) + int(b0) + con
            if(c0==2):
                c0 = 0
                con = 1
            elif(c0==3):
                c0 = 1
                con = 1
            else:
                con = 0
            c = str(c0) + c
        if(con==1): c = '1' + c
        return c

# method(2) 这个方法会导致溢出，这里也不是考察这个内容，最后那个'b'代表的是二进制
#        return format(int(a,2)+int(b,2),"b")

# method(3) 这个方法也会导致溢出，这里也不是考察这个内容
#        a=int(a,2)
#        b=int(b,2)
#        c=a+b
#        c_binary=bin(c)
#        c_binary=c_binary[2:]
#        return c_binary
