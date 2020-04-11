class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int xs1 = start1[0], ys1 = start1[1], xs2 = start2[0], ys2 = start2[1];
        int xe1 = end1[0],   ye1 = end1[1],   xe2 = end2[0],   ye2 = end2[1];
        int x1 = xe1 - xs1, y1 = ye1 - ys1;
        int x2 = xe2 - xs2, y2 = ye2 - ys2;
        int A1 = -y1, B1 = x1, C1 = y1*xs1 - x1*ys1;  // A*x + B*y + C = 0
        int A2 = -y2, B2 = x2, C2 = y2*xs2 - x2*ys2;
        int base = A1*B2 - A2*B1;
        vector<double> nums;
        if(base == 0) {   // parallel
            vector<pair<int,int>> xy;
            if(A1*xs2 + B1*ys2 + C1 == 0) {
                if((xs1-xs2)*(xs1-xe2)<=0 && (ys1-ys2)*(ys1-ye2)<=0) {
                    xy.emplace_back(xs1, ys1);
                }
                if((xs2-xs1)*(xs2-xe1)<=0 && (ys2-ys1)*(ys2-ye1)<=0) {
                    xy.emplace_back(xs2, ys2);
                }
                if((xe1-xs2)*(xe1-xe2)<=0 && (ye1-ys2)*(ye1-ye2)<=0) {
                    xy.emplace_back(xe1, ye1);
                }
                if((xe2-xs1)*(xe2-xe1)<=0 && (ye2-ys1)*(ye2-ye1)<=0) {
                    xy.emplace_back(xe2, ye2);
                }
                if(!xy.empty()) {
                    sort(xy.begin(),xy.end());
                    nums.push_back(xy[0].first);
                    nums.push_back(xy[0].second);
                }
            }
        } else {
            double x = (B1*C2 - B2*C1)/(double)base + 0.0;  // crossover point
            double y = (A2*C1 - A1*C2)/(double)base + 0.0;  // -0.0 => 0.0
            // if point (x, y) is on the lines.
            if((x-xs1)*(x-xe1)<=0 && (x-xs2)*(x-xe2)<=0 &&
               (y-ys1)*(y-ye1)<=0 && (y-ys2)*(y-ye2)<=0) {
                nums.push_back(x);
                nums.push_back(y);
            }
        }
        return nums;
    }
};