class Solution:
    def spiralMatrixIII(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """

        trace = [[r0,c0]]
        up    = r0
        right = c0 + 1
        down  = r0 + 1
        left  = c0 - 1

        nums = 2
        direct = 0

        while(nums<=R*C): #
            if direct==0:
                if(up>=0):
                    for i in range(max(left+2,0), min(right+1,C)):
                        trace.append([up,i])
                        nums += 1
                up = up - 1
                direct = 1
            elif direct==1:
                if(right<C):
                    for i in range(max(up+2,0), min(down+1,R)):
                        trace.append([i,right])
                        nums += 1
                right = right + 1
                direct = 2
            elif direct==2:
                if(down<R):
                    for i in range(max(left,0), min(right-1,C))[::-1]:
                        trace.append([down,i])
                        nums += 1
                down = down + 1
                direct = 3
            elif direct==3:
                if(left>=0):
                    for i in range(max(up,0), min(down-1,R))[::-1]:
                        trace.append([i,left])
                        nums += 1
                left = left - 1
                direct = 0
        return trace
