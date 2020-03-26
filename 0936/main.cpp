template<typename T, typename U>
struct pair_hash {
    size_t operator()(pair<T, U> p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_set<pair<int, int>, pair_hash<int, int>> nums;
        for(auto &p : points) {
            nums.emplace(p[0], p[1]);
        }

        long x1, y1, x2, y2, x3, y3, x4, y4;;
        double minArea = 1e12;
        for(int i=0;i<points.size();++i) {
            x1 = points[i][0]; y1 = points[i][1];
            for(int j=i+1;j<points.size();++j) {
                x2 = points[j][0]; y2 = points[j][1];
                for(int k=j+1;k<points.size();++k) {
                    x3 = points[k][0]; y3 = points[k][1];
                    if((x3-x1)*(x1-x2)+(y3-y1)*(y1-y2)==0) {
                        x4 = x2 + x3 - x1; y4 = y2 + y3 - y1;
                        if(nums.count(make_pair(x4,y4))) {
                            minArea = min(minArea, sqrt(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))*
                                                        ((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))));
                        }
                    }

                }
            }
        }
        return minArea >= 1e12 ? 0.0 : minArea;
    }
};