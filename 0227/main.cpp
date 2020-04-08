class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        char oper = '+';
        ostringstream str;
        stack<int> nums;
        stack<char> opers;
        s.push_back('+');
        for(char ss : s) {
            if(ss==' ') {
                continue;
            } else if(ss=='*' || ss=='/') {
                if(oper=='+' || oper=='-') {
                    nums.push(sum);
                    opers.push(oper);
                    sum = stoi(str.str());
                    str.str("");
                } else if(oper=='*') {
                    sum = sum * stoi(str.str());
                    str.str("");
                } else {
                    sum = sum / stoi(str.str());
                    str.str("");
                }
                oper = ss;
            } else if(ss=='+' || ss=='-') {
                int num;
                if(oper=='*' || oper=='/') {
                    if(oper=='*') {
                        sum = sum * stoi(str.str());
                        str.str("");
                    } else {
                        sum = sum / stoi(str.str());
                        str.str("");
                    }
                    oper = opers.top();
                    num = sum;
                    sum = nums.top();
                    opers.pop();
                    nums.pop();
                } else {
                    num = stoi(str.str());
                    str.str("");
                }
                if(oper=='+') {
                    sum = sum + num;
                    str.str("");
                } else if(oper=='-') {
                    sum = sum - num;
                    str.str("");
                }
                oper = ss;
            } else {
                str<<ss;
            }
        }
        return sum;
    }
};