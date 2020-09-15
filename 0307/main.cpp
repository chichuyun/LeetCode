class NumArray {
private:
    vector<int> tree;  // first index is 1.
    vector<int>& nums;
    int len;

    int _lowbit(int x) {
        return x & (-x);
    }

    void _add_sum(int i, int& val) {
        while(i <= len) {
            tree[i] += val;
            i += _lowbit(i);
        }
    }

    void _buildTree(vector<int>& nums) {
        tree.resize(len+1, 0);
        for(int i=1; i<=len; ++i) {
            _add_sum(i, nums[i-1]);
        }
    }

    int _sum(int i) {
        int res;
        while(i > 0) {
            res += tree[i];
            i -= _lowbit(i);
        }
        return res;
    }
public:
    NumArray(vector<int>& nums) : nums(nums) {
        len = nums.size();
        _buildTree(nums);
    }
    
    void update(int i, int val) {
        val = val - nums[i];
        nums[i] += val;
        _add_sum(i+1, val);
    }
    
    int sumRange(int i, int j) {
        return _sum(j+1) - _sum(i+1) + nums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */