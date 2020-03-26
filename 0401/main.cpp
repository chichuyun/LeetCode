class Solution {
private:
    int count(int n) {
        int res=0;
        while(n) {
            ++res;
            n &= n-1;
        }
        return res;
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> nums;
        ostringstream str;

        for(int i=0;i<12;++i) {
            for(int j=0;j<60;++j) {
                if(count(i)+count(j)==num) {
                    str<<i<<':';
                    if(j<10) str<<0;
                    str<<j;
                    nums.push_back(str.str());
                    str.str("");
                }
            }
        }
        return nums;
    }
};