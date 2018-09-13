class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """

        ans = '1'
        for _ in range(n-1):
            temp_ans = ans
            ans = ''
            counts = 1
            temp = temp_ans[0]
            for x in temp_ans[1:]:
                if temp == x:
                    counts += 1
                else:
                    ans += str(counts) + temp
                    temp = x
                    counts = 1
            ans += str(counts) + temp
        return ans
