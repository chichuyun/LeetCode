class Solution {
public:
    string numberToWords(int num) {
        unordered_map<int,string> nums = {
            {0,"Zero"}, {1,"One"}, {2,"Two"}, {3,"Three"}, {4,"Four"}, {5,"Five"},
            {6,"Six"}, {7,"Seven"}, {8,"Eight"}, {9,"Nine"}, {10,"Ten"}, {11,"Eleven"},
            {12,"Twelve"}, {13,"Thirteen"}, {14,"Fourteen"}, {15,"Fifteen"}, {16,"Sixteen"},
            {17,"Seventeen"}, {18,"Eighteen"}, {19,"Nineteen"}, {20,"Twenty"}, {30,"Thirty"},
            {40,"Forty"}, {50,"Fifty"}, {60,"Sixty"}, {70,"Seventy"}, {80,"Eighty"},
            {90,"Ninety"}, {100,"Hundred"}
        };
        unordered_map<int,string> bases = {{0,""}, {1,"Thousand"}, 
                                           {2,"Million"}, {3,"Billion"}};
        if(num==0) return nums[0];
        vector<int> str;
        while(num!=0) {
            str.push_back(num%1000);
            num /= 1000;
        }
        vector<string> res;
        for(int i=0;i<str.size();++i) {
            ostringstream n;
            int m = str[i];
            if(m>=100) n<<" "<<nums[m/100]<<" "<<nums[100]<<" ";
            m %= 100;
            if(m!=0) {
                if(m<=19) {
                    n<<" "<<nums[m]<<" ";
                } else {
                    n<<" "<<nums[m/10*10]<<" ";
                    if(m%10!=0) n<<nums[m%10]<<" ";
                }
                n<<bases[i]<<" ";
            } else if(str[i]!=0) {
                n<<bases[i]<<" ";
            }
            res.push_back(n.str());
            n.str("");
        }
        reverse(res.begin(),res.end());
        ostringstream strs;
        for(string s:res) strs<<s;
        string ss = strs.str();
        ss = ss.substr(ss.find_first_not_of(' '), ss.find_last_not_of(' '));
        ostringstream last;
        int i=0;
        while(i<ss.size()) {
            if(ss[i]!=' ') {
                last<<ss[i];
                ++i;
            } else {
                last<<' ';
                while(ss[i]==' ') ++i;
            }
        }
        return last.str();
    }
};