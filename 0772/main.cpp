class Solution {
private:
    int priority(string& c) {
        if(c == "+" || c == "-") return 1;
        if(c == "*" || c == "/") return 2;
        return 0;  // '('
    }

    long calculate(vector<string> strs) {
        stack<long> nums;
        for(string& s : strs) {
            if(isdigit(s[0])) {
                nums.push(atoi(s.c_str()));
            } else {
                long num2 = nums.top(); nums.pop();
                long num1 = nums.top(); nums.pop();
                long num;
                switch(s[0]) {
                    case '+':
                        num = num1 + num2;
                        break;
                    case '-':
                        num = num1 - num2;
                        break;
                    case '*':
                        num = num1 * num2;
                        break;
                    case '/':
                        num = num1 / num2;
                        break;
                }
                nums.push(num);
            }
        }
        return nums.top();
    }
public:
    int calculate(string s) {
        ostringstream str;
        vector<string> inorder;
        bool flag = false;
        for(auto& c : s) {
            if(c == ' ') continue;
            if(isdigit(c)) {
                str << c;
                flag = true;
            } else {
                if(flag) {
                    inorder.push_back(str.str());
                    str.str("");
                    flag = false;
                }
                inorder.push_back(string(1, c));
            }
        }
        if(flag) inorder.push_back(str.str());

        stack<string> opers, nums;
        vector<string> postorder;
        
        for(auto& c : inorder) {
            if(isdigit(c[0])) {
                postorder.push_back(c);
            } else if(c == "(") {
                opers.push(c);
            } else if(c == ")") {
                while(opers.top() != "(") {
                    postorder.push_back(opers.top());
                    opers.pop();
                }
                opers.pop(); // pop out '('
            } else {
                if(!opers.empty()) {
                    while(!opers.empty() && priority(c) <= priority(opers.top())) {
                        postorder.push_back(opers.top());
                        opers.pop();
                    }
                }
                opers.push(c);
            }
        }
        while(!opers.empty()) {
            postorder.push_back(opers.top());
            opers.pop();
        }
        
        return calculate(postorder);
    }
};