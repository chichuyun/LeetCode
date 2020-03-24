bool helper(int& x, int& y) {
    ostringstream xx, yy;
    xx<<x<<y; yy<<y<<x;
    return xx.str() < yy.str();
}

class Solution {
public:
    string minNumber(vector<int>& nums) {
        if(nums.empty()) return "";
        sort(nums.begin(), nums.end(), helper);

        ostringstream str;
        for(int n : nums) str<<n;
        return str.str();
    }
};