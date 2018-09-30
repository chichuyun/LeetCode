class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        from collections import defaultdict
        cols = defaultdict(list)
        rows = defaultdict(list)
        boxs = defaultdict(list)
        
        for i, L in enumerate(board):
            for j, s in enumerate(L):
                if s in rows[i] or s in cols[j] or s in boxs[(i//3,j//3)]:
                    return False
                elif s != '.':
                    rows[i].append(s)
                    cols[j].append(s)
                    boxs[(i//3,j//3)].append(s)
        return True
