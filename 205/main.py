class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        if len(s)!=len(t):
            return False

        alp_s = dict()
        alp_t = dict()
        i = 1
        for x, y in zip(s, t):
            if x not in alp_s: alp_s[x] = i
            if y not in alp_t: alp_t[y] = i
            if alp_s[x]!=alp_t[y]: return False
            i += 1
        return True
