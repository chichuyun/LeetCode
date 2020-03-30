class Solution {
private:
    void quicksort(vector<int>& nums, int m, int n) {
        if(m>=n) return;
        int q = partition(nums, m, n);
        quicksort(nums, m, q-1);
        quicksort(nums, q+1, n);
    }

    int partition(vector<int>& nums, int m, int n) {
        int v = nums[m];
        int i = m, j = n, k = m;
        while(k <= j) {
            if(nums[k]<v) {
                swap(nums[k], nums[i]);
                ++i;
                ++k;
            } else if(nums[k]>v) {
                swap(nums[k], nums[j]);
                --j;
            } else {
                ++k;
            }
        }

        return (i + j)/2;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};