class Solution {
private:
    int partition(vector<int>& arr, int i, int j) {
        int v = arr[i], count=0, m=i;
        while(m<=j) {
            if(arr[m]<v) {
                swap(arr[i],arr[m]);
                ++i;
                ++m;
            } else if(arr[m]>v) {
                swap(arr[j],arr[m]);
                --j;
            } else {
                ++count;
                ++m;
            }
        }
        return i+count/2;
    }

    void quicksort(vector<int>& arr, int i, int j, int k) {
        if(i>=j) return;
        int m = partition(arr, i, j);
        if(m==k-1) {
            return;
        } else if(m>k-1) {
            quicksort(arr, i, m-1, k);
        } else {
            quicksort(arr, m+1, j, k);
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quicksort(arr, 0, arr.size()-1, k);
        vector<int> nums(arr.begin(),arr.begin()+k);
        return nums;
    }
};