class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        import collections
        vec1 = collections.Counter(nums1)
        vec2 = collections.Counter(nums2)
        return list((vec1 & vec2).elements())
