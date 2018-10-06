class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        from collections import Counter
        keys, values, s = [], [], Counter(s)
        for key, value in s.items():
            keys.append(key)
            values.append(value)
        keys.sort(key=lambda x:s[x], reverse=True)
        return ''.join([x*s[x] for x in keys])
        
