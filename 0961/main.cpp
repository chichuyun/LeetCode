class Solution {
private:
    unordered_set<int> nums;
public:
    int repeatedNTimes(vector<int>& A) {
        nums.insert(A[0]);
        if(nums.find(A[1])!=nums.end()) return A[1]; nums.insert(A[1]);
        if(nums.find(A[2])!=nums.end()) return A[2]; nums.insert(A[2]);
        if(nums.find(A[3])!=nums.end()) return A[3]; nums.insert(A[3]);
        for(int i=4;i<A.size();++i) {
            nums.erase(A[i-4]);
            if(nums.find(A[i])!=nums.end()) {
                return A[i];
            } else {
                nums.insert(A[i]);
            }
        }
        return 0;
    }
};