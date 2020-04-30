class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> nums = {1, 10, 91, 739, 5275, 32491, 168571, 
                            712891, 2345851, 5611771, 8877691};
        return nums[min(n, 10)];
    }
};