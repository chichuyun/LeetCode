class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        vector<double> res(4,0);
        double cen_x1=square1[0], cen_y1=square1[1];
        double cen_x2=square2[0], cen_y2=square2[1];
        cen_x1 += square1[2]/2.0;
        cen_y1 += square1[2]/2.0;
        cen_x2 += square2[2]/2.0;
        cen_y2 += square2[2]/2.0;
        if(cen_x1==cen_x2) {
            res[0] = cen_x1;
            res[1] = min(square1[1], square2[1]);
            res[2] = cen_x1;
            res[3] = max(square1[1]+square1[2], square2[1]+square2[2]);
        } else if(cen_y1==cen_y2) {
            res[0] = min(square1[0], square2[0]);
            res[1] = cen_y1;
            res[2] = max(square1[0]+square1[2], square2[0]+square2[2]);
            res[3] = cen_y1;
        } else {
            double k = (cen_y2-cen_y1)/(cen_x2-cen_x1);
            double b = cen_y1 - k*cen_x1;
            if(fabs(k)<1) {
                res[0] = min(square1[0], square2[0]);
                res[1] = k*res[0] + b;
                res[2] = max(square1[0]+square1[2], square2[0]+square2[2]);
                res[3] = k*res[2] + b;
            } else {
                if(k>0) {
                    res[1] = min(square1[1], square2[1]);
                    res[0] = (res[1] - b)/k;
                    res[3] = max(square1[1]+square1[2], square2[1]+square2[2]);
                    res[2] = (res[3] - b)/k;
                } else {
                    res[1] = max(square1[1]+square1[2], square2[1]+square2[2]);
                    res[0] = (res[1] - b)/k;
                    res[3] = min(square1[1], square2[1]);
                    res[2] = (res[3] - b)/k;
                }
            }
        }
        return res;
    }
};