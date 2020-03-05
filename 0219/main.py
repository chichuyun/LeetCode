class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        
        num = dict()
        for i, n in enumerate(nums):
            if n in num:
                if i - num[n] > k:
                    num[n] = i
                else:
                    return True
            else:
                num[n] = i
        return False