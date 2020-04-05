class NumArray {
private:
    vector<int> sums;
    vector<int> ns;
public:
    NumArray(vector<int>& nums) {
        sums = nums;
        ns = nums;
        for(int i=1;i<nums.size();++i) {
            sums[i] += sums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j] - sums[i] + ns[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */