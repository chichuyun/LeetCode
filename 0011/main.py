class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
# method(1) 枚举,会超时
#        temp = 0
#        max0 = 0
#        for i in range(len(height)):
#            j = i
#            while(j<len(height)):
#                temp = min(height[i],height[j])*(j-i)
#                if(temp>max0): max0 = temp
#                j += 1
#        return max0
# method(2) 双指针,两边夹
        left = 0
        right = len(height) - 1
        ans = 0
        while(right!=left):
            temp = min(height[left], height[right])*(right - left)
            ans = max(temp, ans)
            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
        return ans
