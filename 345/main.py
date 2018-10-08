class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        alp = set('aeiouAEIOU')
        left = 0
        right = len(s) - 1
        
        s = list(s)
        while(left < right):
            if s[left] not in alp:
                left += 1
                continue
            if s[right] not in alp:
                right -= 1
                continue
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
            
        return ''.join(s)
