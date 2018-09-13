class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
# method(1) list可重新赋值
        temp = set([""])
        for k in range(n):
            ans = set()
            for string in temp:
                for i in range(k+1):
                    temp0 = list(string)
                    temp0.insert(i,')')
                    temp0.insert(i,'(')
                    ans.add(''.join(temp0))
            temp = ans.copy()
        return list(temp)

# method(2) string相加
#        temp = set([""])
#        for i in range(n):
#            ans = set()
#            for string in temp:
#                for j in range(len(string)):
#                    ans.add(string[:j]+"()"+string[j:])
#                ans.add(string+"()")
#            temp = ans
#        return list(temp)
