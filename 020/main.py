class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        a = {'(':')','[':']','{':'}'}
        
        temp = list()
        
        for bra in s:
            if bra in a:
                temp.append(bra)
            elif temp==[] or a[temp[-1]]!=bra:
                return False
            else:
                del temp[-1]

        if temp==[]:    
            return True
        else:
            return False
                
                
