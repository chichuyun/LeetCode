class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return matrix;
        
        queue<pair<int,int>> indexs;
        int cols=matrix.size(), rows=matrix[0].size();        
        for(int i=0;i<cols;++i) {
            for(int j=0;j<rows;++j) {
                if(matrix[i][j]==0) {
                    if(i-1>=0 && matrix[i-1][j]==1) {
                        matrix[i-1][j] = -1;
                        indexs.emplace(i-1,j);
                    }
                    if(i+1<cols && matrix[i+1][j]==1) {
                        matrix[i+1][j] = -1;
                        indexs.emplace(i+1,j);
                    }
                    if(j-1>=0 && matrix[i][j-1]==1) {
                        matrix[i][j-1] = -1;
                        indexs.emplace(i,j-1);
                    }
                    if(j+1<rows && matrix[i][j+1]==1) {
                        matrix[i][j+1] = -1;
                        indexs.emplace(i,j+1);
                    }
                }
            }
        }
        
        int num=1, count;
        while(!indexs.empty()) {
            ++num;
            count = indexs.size();
            while(count) {
                int i = indexs.front().first;
                int j = indexs.front().second;
                indexs.pop();
                if(i-1>=0 && matrix[i-1][j]==1) {
                    matrix[i-1][j] = -num;
                    indexs.emplace(i-1,j);
                }
                if(i+1<cols && matrix[i+1][j]==1) {
                    matrix[i+1][j] = -num;
                    indexs.emplace(i+1,j);
                }
                if(j-1>=0 && matrix[i][j-1]==1) {
                    matrix[i][j-1] = -num;
                    indexs.emplace(i,j-1);
                }
                if(j+1<rows && matrix[i][j+1]==1) {
                    matrix[i][j+1] = -num;
                    indexs.emplace(i,j+1);
                }
                --count;
            }

        }
        
        for(int i=0;i<cols;++i) {
            for(int j=0;j<rows;++j) {
                matrix[i][j] = -matrix[i][j];
            }
        }
        
        return matrix;
    }
};