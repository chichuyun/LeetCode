class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
#        from collections import Counter
#        string = Counter(s)
#        temp = []
#        for x, i in string.items():
#            if(i==1): temp.append(x)
#        if(temp==[]): return -1
#        for i, x in enumerate(s):
#            if(x in temp):
#                return i

        index = len(s)
        for x in set(s):
            left = s.find(x)
            right = s.rfind(x)
            
            if left == right and left != -1:
                index = min(index, left)
        
        if index < len(s):
            return index
        else:
            return -1
