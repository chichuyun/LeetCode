class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> counts;
        for(int n : deck) ++counts[n];
        int num = INT_MAX;
        for(auto count : counts) {
            num = min(num, count.second);
        }
        int flag;
        for(int i=2;i<=num;++i) {
            flag = 1;
            for(auto count : counts) {
                if(count.second%i!=0) {
                    flag = 0;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};