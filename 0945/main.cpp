class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()<2) return 0;
        sort(A.begin(),A.end());

        int count=0;
        for(int i=1;i<A.size();++i) {
            if(A[i]<=A[i-1]) {
                count += A[i-1] - A[i] + 1;
                A[i] = A[i-1] + 1;
            }
        }
        return count;

/* time out
        if(A.size()<2) return 0;
        vector<int> nums(80000,0);
        int count=0;
        for(int n : A) {
            int m = n;
            while(nums[n]!=0) ++n;
            nums[n] = 1;
            count += n - m;
        }
        return count;
*/
    }
};