class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        
        s_l = len(s)
        index = list([i] for i in range(max(s_l-9, 1), min(s_l-3, 3)+1) \
                    if s[:i]==str(int(s[:i])) and int(s[:i]) < 256)
        
        for i in range(2,0,-1):
            temp = index.copy()
            index.clear()
            for L in temp:
                num = L[-1]
                for n in range(max(s_l-num-3*i, 1), min(s_l-num-i, 3)+1):
                    if s[num:num+n] == str(int(s[num:num+n])) and \
                                           int(s[num:num+n]) < 256:
                        index.append(L + [num+n])

        return [s[:L[0]]+'.'+s[L[0]:L[1]]+'.'+s[L[1]:L[2]]+'.'+s[L[2]:] \
                for L in index if s[L[2]:] == str(int(s[L[2]:])) and int(s[L[2]:]) < 256]
            
        
