class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int aMin = INT_MAX, bMin = INT_MAX, cMin = INT_MAX, dMin = INT_MAX;
        int aMax = INT_MIN, bMax = INT_MIN, cMax = INT_MIN, dMax = INT_MIN;
        for(int i=0; i<arr1.size(); ++i) {
            int &x = arr1[i], &y = arr2[i];
            aMin = min(x+y+i, aMin);
            aMax = max(x+y+i, aMax);
            bMin = min(x+y-i, bMin);
            bMax = max(x+y-i, bMax);
            cMin = min(x-y+i, cMin);
            cMax = max(x-y+i, cMax);
            dMin = min(x-y-i, dMin);
            dMax = max(x-y-i, dMax);
        }

        return max(max(aMax-aMin,bMax-bMin),max(cMax-cMin,dMax-dMin));
    }
};