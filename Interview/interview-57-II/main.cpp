class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> nums;
        int max=2, min=1, max_num, count=3;
        max_num = target%2 ? target/2+1 : target/2;
        for(;;) {
            if(count==target) {
                vector<int> num;
                for(int i=min;i<=max;++i) {
                    num.push_back(i);
                }
                nums.push_back(num);
                count -= min;
                ++max;
                count += max;
                ++min;
            } else if(count<target) {
                ++max;
                count += max;
            } else {
                count -= min;
                ++min;
            }
            if(min>max_num || max>max_num) break;
        }
        return nums;
    }
};