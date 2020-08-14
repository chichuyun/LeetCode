class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int n = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> adjs(rows*cols);
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(j+1 < cols) {
                    if(matrix[i][j] > matrix[i][j+1]) adjs[n+1].push_back(n);
                    if(matrix[i][j] < matrix[i][j+1]) adjs[n].push_back(n+1);
                }
                if(i+1 < rows) {
                    if(matrix[i][j] > matrix[i+1][j]) adjs[n+cols].push_back(n);
                    if(matrix[i][j] < matrix[i+1][j]) adjs[n].push_back(n+cols);
                }
                ++n;
            }
        }
        
        vector<int> indegrees(rows*cols,0);
        for(int i=0; i<adjs.size(); ++i) {
            for(int j : adjs[i]) {
                indegrees[j]++;
            }
        }
        int count = 0;
        queue<int> nodes;
        for(int i=0; i<indegrees.size(); ++i) {
            if(indegrees[i]==0) nodes.push(i);
        }

        while(!nodes.empty()) {
            int n = nodes.size();
            ++count;
            while(n--) {
                int index = nodes.front();
                nodes.pop();
                for(int j : adjs[index]) {
                    indegrees[j]--;
                    if(indegrees[j]==0) nodes.push(j);
                }
            }
        }

        return count;
    }
};