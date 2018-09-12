class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
# method(1) 很一般的方法
        if len(strs)==0: return ""
        length = min([len(char) for char in strs])
        
        temp = ''
        for i in range(length):
            char = strs[0][i]
            for string in strs:
                if char!=string[i]:
                    return temp
            temp = temp + char
        return temp

# method(2) min函数的巧用
#        if not strs:
#            return ""
#        shortest=min(strs,key=len)
#        for x, y in enumerate(shortest):
#            for s in strs:
#                if s[x]!=y:
#                    return shortest[:x]
#        return shortest
