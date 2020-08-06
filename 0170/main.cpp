class TwoSum {
private:
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        unordered_set<int> sets;
        for(int i=0; i<nums.size(); ++i) {
            if(sets.count(value-nums[i])) {
                return true;
            } else {
                sets.insert(nums[i]);
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */