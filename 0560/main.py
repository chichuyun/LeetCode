class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        pres = {0:1};
        count, pre = 0, 0
        for n in nums:
            pre += n
            if pre - k in pres:
                count += pres[pre-k]
            if pre in pres:
                pres[pre] += 1
            else:
                pres[pre] = 1
        return count