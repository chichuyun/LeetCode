class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) <= 1: return 0

        minp = prices[0]
        res = 0
        for p in prices:
            temp = p - minp
            if temp > res: res = temp
            if temp < 0: minp = p
        return res
