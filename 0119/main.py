class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        res = []
        for _ in range(rowIndex+1):
            temp = res.copy()
            for i in range(1,len(temp)):
                res[i] = temp[i-1] + temp[i]
            res.append(1)
        return res
