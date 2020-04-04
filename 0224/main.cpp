class Solution {
private:
    unordered_map<char,function<int(int,int)>> func = {{'+',plus<int>()},{'-',minus<int>()}};
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> opers;
        s = '(' + s + ')';
        int res = 0;
        char op = '+';
        ostringstream n;
        for(char str : s) {
            if(str!=' ') {
                if(str=='(') {
                    nums.push(res);
                    opers.push(op);
                    res = 0;
                    op = '+';
                } else if(str==')') {
                    int num = n.str().empty() ? res : func[op](res, stoi(n.str()));
                    res = func[opers.top()](nums.top(), num);
                    nums.pop();
                    opers.pop();
                    n.str("");
                } else if(str=='+') {
                    if(!n.str().empty()) {
                        res = func[op](res, stoi(n.str()));
                    }
                    op = '+';
                    n.str("");
                } else if(str=='-') {
                    if(!n.str().empty()) {
                        res = func[op](res, stoi(n.str()));
                    }
                    op = '-';
                    n.str("");
                } else {
                    n<<str;
                }
            }
        }
        return res;
    }
};