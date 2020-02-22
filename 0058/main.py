class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s.split() == []:
            return 0
        else:
            return len(s.split()[-1])
