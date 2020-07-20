class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            vector<int> ts = nums1;
            nums1 = nums2;
            nums2 = ts;
        }
        
        int len1 = nums1.size(), len2 = nums2.size();
        int len = len1 + len2;
        int half = (len + 1)/2;

        int left = 0, right = len1, mid1, mid2;
        double num1_l, num1_r, num2_l, num2_r, mids1, mids2;
        while(left <= right) {
            mid1 = left + (right - left)/2;
            mid2 = half - mid1;
            
            num1_l = mid1 == 0 ? INT_MIN : nums1[mid1-1];
            num1_r = mid1 == len1 ? INT_MAX : nums1[mid1];
            num2_l = mid2 == 0 ? INT_MIN : nums2[mid2-1];
            num2_r = mid2 == len2 ? INT_MAX : nums2[mid2];

            if(num1_l <= num2_r) {
                left = mid1 + 1;

                mids1 = max(num1_l, num2_l);
                mids2 = min(num1_r, num2_r);
            } else {
                right = mid1 - 1;
            }
        }
        
        double res;
        if(len%2 == 1) {
            res = mids1;
        } else {
            res = (mids1 + mids2)/2.0;
        }

        return res;
    }
};