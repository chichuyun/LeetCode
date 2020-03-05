class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        count = len(list1) + len(list2)
        dics = dict()
        nums = list()
        
        for i, s in enumerate(list1):
            dics[s] = i
        for i, s in enumerate(list2):
            if s in dics:
                if i + dics[s] < count:
                    count = i + dics[s]
                    nums.clear()
                    nums.append(s)
                elif i + dics[s] == count:
                    nums.append(s)

        return nums
        