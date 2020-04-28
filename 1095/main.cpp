/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int maxIndex;
        int left = 0, right = len - 1, mid;
        while(left + 1 < right) {
            mid = left + (right - left)/2;
            int num = mountainArr.get(mid);
            int numleft = mountainArr.get(mid-1);
            int numright = mountainArr.get(mid+1);
            if(num > numleft && num > numright) {
                maxIndex = mid;
                break;
            } else if(num > numleft) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if(mountainArr.get(maxIndex)==target) return maxIndex;
        left = 0;
        right = maxIndex;
        while(left <= right) {  // left up
            mid = left + (right - left)/2;
            int num = mountainArr.get(mid);
            if(num==target) {
                return mid;
            } else if(target > num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        left = maxIndex;
        right = len - 1;
        while(left <= right) {  // right down
            mid = left + (right - left)/2;
            int num = mountainArr.get(mid);
            if(num==target) {
                return mid;
            } else if(target > num) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};