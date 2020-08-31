class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int len = arr.size();
        if(len/m < k) return false;
        if(len >= m && k == 1) return true;
        int count;
        for(int i=0; i<=len-m; ++i) {
            int j = i + m;
            count = 1;
            while(j <= len-m) {
                bool flag = true;
                for(int z=0; z<m; ++z) {
                    if(arr[i+z] != arr[j+z]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    j += m;
                    ++count;
                    if(count >= k) return true;
                } else {
                    break;
                }
            }
        }

        return false;
    }
};