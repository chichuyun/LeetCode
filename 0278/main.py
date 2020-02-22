# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
# 这个题是右相关,左相关则类似
        left, right = 0, n
        while left < right:
            mid = (left + right)//2
            if isBadVersion(mid):
                right = mid     # 这里能保证right一定是True
            else:
                left = mid + 1  # 一直向True靠拢
        return right
