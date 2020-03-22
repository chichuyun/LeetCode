class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> nums;
        if(matrix.empty() || matrix.empty()) return nums;
        int t=0, b=matrix.size()-1, l=0, r=matrix[0].size()-1;
        int count=matrix.size()*matrix[0].size();
        nums.resize(count);
        int n=0, flag=1;
        while(n<count) {
            switch(flag) {
            case 1:
                for(int i=l;i<=r;++i) {
                    nums[n] = matrix[t][i];
                    ++n;
                }
                ++t; ++flag; break;
            case 2:
                for(int j=t;j<=b;++j) {
                    nums[n] = matrix[j][r];
                    ++n;
                }
                --r; ++flag; break;
            case 3:
                for(int i=r;i>=l;--i) {
                    nums[n] = matrix[b][i];
                    ++n;
                }
                --b; ++flag; break;
            case 4:
                for(int j=b;j>=t;--j) {
                    nums[n] = matrix[j][l];
                    ++n;
                }
                ++l; flag=1; break;
            }
        }
        return nums;
    }
};