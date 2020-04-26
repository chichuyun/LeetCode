class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even = 0, odd = 1, i = 0;
        while(i < A.size()) {
            if(A[i]&1==1) {
                if(i&1==0) {
                    swap(A[i], A[odd]);
                    odd += 2;
                }
                ++i;
            } else if(i&1) {
                swap(A[i], A[even]);
                even += 2;
            } else {
                ++i;
            }
        }
        return A;
    }
};