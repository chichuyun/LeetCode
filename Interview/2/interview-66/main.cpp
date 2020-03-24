class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size()<2) return a;
        vector<int> nums(a.size(),1);
        
        int left=1, right=1;
        for(int i=1;i<a.size();++i) {
            left *= a[i-1];
            nums[i] = left;
        }
        for(int i=a.size()-2;i>=0;--i) {
            right *= a[i+1];
            nums[i] *= right;
        }
        return nums;
    }
};