class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
# method(1) 乘法竖乘套路
        if num1=='0' or num2=='0': return '0'
        num1_s = list(map(int, num1))
        num2_s = list(map(int, num2))
        
        res = '0'
        for i, num in enumerate(num2_s[::-1]):
            # 乘法
            temp = ''
            con = 0 # 进位
            for t in num1_s[::-1]:
                n = num*t + con
                con = n//10
                temp = str(n%10) + temp
            if con != 0: temp = str(con) + temp
            # 加法
            temp += '0'*i
            temp_res = ''
            len1, len2 = len(temp), len(res)
            if len1 > len2:
                res = '0'*(len1-len2) + res
            else:
                temp = '0'*(len2-len1) + temp
            con = 0 # 进位
            for n1, n2 in zip(res[::-1], temp[::-1]):
                n = int(n1) + int(n2) + con
                con = n//10
                temp_res = str(n%10) + temp_res
            if con != 0: temp_res = str(con) + temp_res
            res = temp_res
        return res
        
# method(2) 不急的去进位, 随后专门进位
'''
        num1 = num1[::-1]; num2 = num2[::-1]
        res = [0 for i in range(len(num1) + len(num2))]
        for i in range(len(num1)):
            for j in range(len(num2)):
                res[i+j] += int(num1[i]) * int(num2[j])
                
        p = 0; flag = 0
        for i in range(len(res)):
            p = (res[i] + flag) % 10
            flag = (res[i] + flag) // 10
            res[i] = str(p)
            
        res.append(str(flag))
        index = len(res) - 1
        
        while index > 0 and res[index] == '0':  #最后去除最高位的0
            del(res[index])
            index -= 1
        
        return ''.join(res[::-1])
'''
