class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int,int)>> opers{{"+",plus<int>()}, {"-",minus<int>()},
                                                            {"*",multiplies<int>()}, {"/",divides<int>()}};
        stack<int> nums;
        for(auto token : tokens) {
            if(opers.find(token)==opers.end()) {
                nums.push(stoi(token));
            } else {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                nums.push(opers[token](left,right));
            }
        }
        return nums.top();
    }
};