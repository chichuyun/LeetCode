class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        
        res = []
        set_s = dict()
        i = 0
        for s in strs:
            sort_s = ''.join(sorted(s))
            if sort_s in set_s:
                res[set_s[sort_s]].append(s)
            else:
                set_s[sort_s] = i
                res.append([])
                res[i].append(s)
                i += 1
        return res
                
