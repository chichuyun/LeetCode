class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>> indexs;
        pair<int,int> nums;
        int l, r, t, b, i, j;
        int cols=image.size(), rows=image[0].size();
        int color=image[sr][sc];
        
        if(color==newColor) return image;
        image[sr][sc] = newColor;
        indexs.push(make_pair(sr,sc));
        while(!indexs.empty()) {
            nums = indexs.front();
            indexs.pop();
            i = nums.first;
            j = nums.second;
            l = i - 1;
            r = i + 1;
            t = j - 1;
            b = j + 1;
            if(l >= 0) {
                if(image[l][j]==color) {
                    image[l][j]=newColor;
                    indexs.push(make_pair(l,j));
                }
            }
            if(r < cols) {
                if(image[r][j]==color) {
                    image[r][j]=newColor;
                    indexs.push(make_pair(r,j));
                }
            }
            if(t >= 0) {
                if(image[i][t]==color) {
                    image[i][t]=newColor;
                    indexs.push(make_pair(i,t));
                }
            }
            if(b < rows) {
                if(image[i][b]==color) {
                    image[i][b]=newColor;
                    indexs.push(make_pair(i,b));
                }
            }
        }
        return image;
    }
};