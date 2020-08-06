class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int count = 0; // the total number of candy
        int nums = 0;  // the number of decreasing ratings
        int num = 0;   // the number of candy
        int pre = INT_MIN; // previous rating
        int pre_max = INT_MAX; // previous max candy
        for(int& rating : ratings) {
            if(rating < pre) {  // decreasing
                num = 1;
                nums++;
                count += nums;
                count += max(0, min(1+nums-pre_max, 1)); // two sides, left and right
            } else if(rating == pre) {
                num = 1;
                nums = 0;
                count += num;
                pre_max = 1;
            } else { // increaing
                num += 1;
                nums = 0;
                count += num;
                pre_max = num;
            }
            pre = rating;
        }

        return count;
    }
};