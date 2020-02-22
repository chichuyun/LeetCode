class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if len(matrix)==0: return []

        temp = []
        flag = 0
        up, left = 0, 0
        down, right = len(matrix)-1, len(matrix[0])-1
        while up <= down and left <= right:
            if flag==0:   # right
                for i in range(left,right+1):
                    temp.append(matrix[up][i])
                up += 1
                flag = 1
            elif flag==1: # down
                for i in range(up,down+1):
                    temp.append(matrix[i][right])
                right -= 1
                flag = 2
            elif flag==2: # left
                for i in range(left,right+1)[::-1]:
                    temp.append(matrix[down][i])
                down -= 1
                flag = 3
            else:         # up
                for i in range(up,down+1)[::-1]:
                    temp.append(matrix[i][left])
                left += 1
                flag = 0
        return temp
