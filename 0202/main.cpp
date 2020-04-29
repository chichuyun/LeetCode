class Solution {
private:
    int get_num(int num) {
        int hap = 0;
        while(num) {
            hap += (num%10)*(num%10);
            num /= 10;
        }
        return hap;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        int num = n;
        nums.insert(num);
        for(;;) {
            if(num == 1) return true;
            num = get_num(num);
            if(nums.count(num)) return false;
            nums.insert(num);
        }
        return true;
    }
};