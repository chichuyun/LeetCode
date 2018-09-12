class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if(numRows==0): return []
        
        mat = [[1]]
        for i in range(1,numRows):
            temp = [0]+mat[i-1]+[0]
            vec = []
            for j in range(i+1):
                vec.append(temp[j]+temp[j+1])
            mat.append(vec)
        return mat
