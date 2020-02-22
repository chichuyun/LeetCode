class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        i, j = m-1 ,n-1
        for _ in range(m+n):
            if(i<0):
                nums1[i+j+1] = nums2[j]
                j -= 1
            elif(j<0):
                nums1[i+j+1] = nums1[i]
                i -= 1
            elif(nums1[i]>nums2[j]):
                nums1[i+j+1] = nums1[i]
                i -= 1
            else:
                nums1[i+j+1] = nums2[j]
                j -= 1
