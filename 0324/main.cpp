class Solution {
private:
    void quickSort(vector<int>& nums, int i, int j, int& k) {
        if(i >= j) return;
        int n = merge(nums, i, j);
        if(n==k) {
            return;
        } else if(n > k) {
            quickSort(nums, i, n-1, k);  // n-1
        } else {
            quickSort(nums, n+1, j, k);  // n+1
        }
    }

    int merge(vector<int>& nums, int i, int j) {
        int v = nums[j];
        int l = i;
        for(int r=i;r<j;++r) {
            if(nums[r] < v) {
                swap(nums[l], nums[r]);
                ++l;
            }
        }
        swap(nums[l],nums[j]);
        return l;
    }
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return;
        int k = len/2 + len%2;
        quickSort(nums, 0, len-1, k);
        vector<int> temp(nums);
        int left = k-1, right = len-1;
        for(int i=0;i<nums.size();++i) {
            if(i&1) {
                nums[i] = temp[right--];
            } else {
                nums[i] = temp[left--];
            }
        }
    }
};