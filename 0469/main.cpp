vector<int> operator-(vector<int> p, vector<int> q) {
     return {p[0] - q[0], p[1] - q[1]}; 
}

class Solution {
private:
    int _cross(vector<int> p, vector<int> q) {
        if(p[0]*q[1] - p[1]*q[0] > 0) return 1;
        if(p[0]*q[1] - p[1]*q[0] < 0) return -1;
        return 0;
    }
public:
    bool isConvex(vector<vector<int>>& points) {
        points.push_back(points[0]);
        points.push_back(points[1]);

        int len = points.size(), sum = 0, t = 0;
        int up = 0, down = 0;
        for(int i=2; i<len; ++i) {
            sum += _cross(points[i] - points[i-1], points[i-1] - points[i-2]);
            if(sum > t) ++up;
            if(sum < t) ++down;
            t = sum;
        }

        return up == 0 || down == 0;
    }
};