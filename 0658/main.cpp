class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> nums(k);
        int minv=0, b=0;
        for(int i=0;i<k;++i) minv += abs(x-arr[i]);
        for(int i=1;i<=arr.size()-k;++i) {
            int num = minv - abs(x-arr[i-1]) + abs(x-arr[i+k-1]);
            if(minv > num) {
                minv = num;
                b = i;
            }
        }
        for(int i=0;i<k;++i) {
            nums[i] = arr[i+b];
        }
        return nums;
/* binary_search
    int lo = 0, hi = arr.size() - k;
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (x - arr[mid] > arr[mid + k] - x ) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
*/
    }
};