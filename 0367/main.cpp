class Solution {
public:
    bool isPerfectSquare(int num) {
        int left=1, right=46340, mid, n;
        while(left<=right) {
            mid = (right+left)/2;
            n = mid*mid;
            if(n==num) {
                return true;
            } else if(n<num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
/*
        int low = 1, height = num, mid;
        while( low <= height ){
            mid = low + ( height - low )/2;
            if( num/mid > mid ){  // to avoid overflow
                low = mid + 1;
            }
            else{
                height = mid - 1;
            }
        }

        return num/low == low && num % low == 0;
*/
    }
};