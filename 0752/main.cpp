class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int count=0, c1, c2;
        string temp;
        queue<string> nums;
        unordered_set<string> deads;
        unordered_map<char,char> table1={{'0','1'},{'1','2'},{'2','3'},{'3','4'},{'4','5'},
                                         {'5','6'},{'6','7'},{'7','8'},{'8','9'},{'9','0'}};
        unordered_map<char,char> table2={{'1','0'},{'2','1'},{'3','2'},{'4','3'},{'5','4'},
                                         {'6','5'},{'7','6'},{'8','7'},{'9','8'},{'0','9'}};
        for(int i=0;i<deadends.size();++i) {
            deads.insert(deadends[i]);
        }
        
        nums.push("0000");
        if(deads.find(nums.front())!=deads.end()) return -1;
        deads.insert("0000");
        c2 = 1;
        while(c2) {
            ++count;
            c1 = c2;
            c2 = 0;
            while(c1) {
                temp = nums.front();
                nums.pop();
                for(int i=0;i<5;++i) {
                    string t(temp);
                    t[i] = table1[temp[i]];
                    if(t==target) {
                        return count;
                    } else if(deads.find(t)==deads.end()) {
                        nums.push(t);
                        deads.insert(t);
                        ++c2;
                    }
                }
                for(int i=0;i<5;++i) {
                    string t(temp);
                    t[i] = table2[temp[i]];
                    if(t==target) {
                        return count;
                    } else if(deads.find(t)==deads.end()) {
                        nums.push(t);
                        deads.insert(t);
                        ++c2;
                    }
                }
                --c1;
            }
        }
        return -1;
    }
};