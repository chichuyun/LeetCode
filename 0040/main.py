class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if not candidates: return []
        
        candidates.sort()
        temp = dict()
        length = len(candidates)
        for i, x in enumerate(candidates[::-1]):
            temp[(x,)] = length - i - 1
        res = set()
        if target in candidates: res.add((target,))
        
        for _ in range(target//candidates[0]):
            res_temp = temp.copy()
            print(temp)
            temp = dict()
            for L, i in res_temp.items():
                for j, x in enumerate(candidates):
                    if j <= i: continue
                    temp_L = L + (x,)
                    sum_L = sum(temp_L)
                    if sum_L == target:
                        res.add(temp_L)
                    elif sum_L < target and temp_L not in temp:
                        temp[temp_L] = j
        return [list(L) for L in res]
                
