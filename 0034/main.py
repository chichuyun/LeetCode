class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        res = [-1, -1]
        if not nums or nums[0] > target or nums[-1] < target: return res

        left, right = 1, len(nums)
        if nums[0] == target:
            res[0] = 0
        else:
            while left < right:
                mid = left + (right - left)//2
                if nums[mid] == target:
                    if nums[mid-1] < target:
                        res[0] = mid
                        break
                    else:
                        right = mid
                elif nums[mid] > target:
                    right = mid
                else:
                    left = mid + 1

        left, right = 0, len(nums)-1
        if nums[right] == target:
            res[1] = right
        else:
            while left < right:
                mid = left + (right - left)//2
                if nums[mid] == target:
                    if nums[mid+1] > target:
                        res[1] = mid
                        break
                    else:
                        left = mid + 1
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid

        return res