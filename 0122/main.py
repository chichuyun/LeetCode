class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        total = 0
        for i in range(len(prices)-1):
            div = prices[i+1] - prices[i]
            if(div>0): total = total + div
        return total
