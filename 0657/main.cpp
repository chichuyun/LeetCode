class Solution {
public:
    bool judgeCircle(string moves) {
        int rows = 0, cols = 0;
        for(char s : moves) {
            switch(s) {
                case 'U':
                    ++cols;
                    break;
                case 'D':
                    --cols;
                    break;
                case 'L':
                    ++rows;
                    break;
                case 'R':
                    --rows;
            }
        }
        return cols == 0 && rows == 0;
    }
};