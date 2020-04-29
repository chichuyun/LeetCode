class Solution {
public:
    int nextGreaterElement(int n) {
        if(n<10) return -1;
        vector<int> tens;
        while(n) {
            tens.push_back(n%10);
            n /= 10;
        }
        bool flag = true;
        for(int i=0;i<tens.size()-1;++i) {
            flag = flag && tens[i] <= tens[i+1];
        }
        if(flag) return -1;
        int index_i = 11, index_j = 11;
        for(int i=0;i<tens.size();++i) {
            for(int j=i+1;j<tens.size();++j) {
                if(tens[j] < tens[i]) {
                    if(index_j > j) {
                        index_j = j;
                        index_i = i;
                        break;
                    }
                }
            }
        }
        swap(tens[index_i], tens[index_j]);
        long num = 0;
        sort(tens.begin(), tens.begin()+index_j, greater<int>());
        for(int i=0;i<tens.size();++i) {
            num += (long)tens[i]*pow(10,i);
        }
        return num > INT_MAX ? -1 : num;
    }
};