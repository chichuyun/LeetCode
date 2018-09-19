class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        mapping = {'2':'abc','3':'def','4':'ghi','5':'jkl',
                   '6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        
        if len(digits)==0: return []
        
        ans = list()
        ans.extend(mapping[digits[0]])
        for s in digits[1:]:
            new = ans.copy()
            ans = list()
            for string in new:
                for x in mapping[s]:
                    ans.append(string+x)
        return ans

''' 递归的方式
class Solution:
    mapping = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', 
               '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) == 0:
            return []
        elif len(digits) == 1:
            return list(self.mapping[digits])
        else:
            return [i + j for i in self.letterCombinations(digits[:-1]) for j in self.letterCombinations(digits[-1])]
'''
