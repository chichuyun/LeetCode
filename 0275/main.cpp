class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int len = citations.size();
        if(citations[len-1]==0) return 0;
        if(citations[0]>=len) return len;
        int left = 0, right = len, mid, h;
        while(left < right) {
            mid = left + (right - left)/2;
            h = len - mid;
            if(h <= citations[mid]) {
                if(citations[mid-1] < h+1) {
                    return h;
                } else {
                    right = mid;
                }
            } else {
                left = mid + 1;
            }
        }
        return h;
    }
};