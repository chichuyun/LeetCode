class Solution:
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        area = 0
        length = len(grid)
        for i, vec in enumerate(grid):
            for j, v in enumerate(vec):
                if(v!=0):
                    area += 2
                if(i==0):
                    area += v
                if(i==length-1):
                    area += v
                if(i>0):
                    div = v - grid[i-1][j]
                    if(div>0): area += div
                if(i<length-1):
                    div = v - grid[i+1][j]
                    if(div>0): area += div
                if(j==0):
                    area += v
                if(j==length-1):
                    area += v
                if(j>0):
                    div = v - vec[j-1]
                    if(div>0): area += div
                if(j<length-1):
                    div = v - vec[j+1]
                    if(div>0): area += div
        return area
