class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if not candidates: return []
        
        candidates.sort()
        temp = [[x] for x in candidates]
        res = list()
        
        if target in candidates: res.append([target])
        for _ in range(target//candidates[0]):
            res_temp = temp.copy()
            temp = list()
            for L in res_temp:
                for x in candidates:
                    if x < L[-1]: continue
                    temp_L = L + [x]
                    sum_L = sum(temp_L)
                    if sum_L == target:
                        res.append(temp_L)
                    elif sum_L < target:
                        temp.append(temp_L)
                    else:
                        break
        return res
                
