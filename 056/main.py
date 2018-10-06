# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals: return []
        intervals.sort(key=lambda x: x.start)
        
        temp = intervals[0]
        res = list()
        for inter in intervals:
            if temp.end >= inter.start:
                temp.end = max(temp.end, inter.end)
            else:
                res.append(temp)
                temp = inter
        res.append(temp)
        return res
