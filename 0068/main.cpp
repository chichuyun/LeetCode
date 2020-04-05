class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> strs;
        int i=0, count, num, ns, nw;
        vector<string> s;
        ostringstream ss;
        bool flag;
        while(i<words.size()) {
            count = 0;
            s.clear();
            ss.str("");
            flag = false;
            for(int j=i;j<words.size();++j) {
                count += words[j].size();
                s.push_back(words[j]);
                if(count+s.size()-1>maxWidth) {
                    flag = true;
                    break;
                }
            }
            if(s.size()!=1 && flag) {
                count -= s.back().size();
                s.pop_back();
            }
            i += s.size() > 0 ? s.size() : 1;
            num = maxWidth - count;
            if(s.size()!=1 && flag) {
                ns = (maxWidth-count)/(s.size()-1);
                nw = (maxWidth-count)%(s.size()-1);
                for(int w=0;w<s.size()-1;++w) {
                    num = nw-- > 0 ? ns+1 : ns;
                    ss<<s[w];
                    while(num--) ss<<' ';
                }
                ss<<s[s.size()-1];
            } else {
                for(int j=0;j<s.size()-1;++j) ss<<s[j]<<' ';
                ss<<s[s.size()-1];
                num = maxWidth - ss.str().size();
                while(num--) ss<<' ';
            }
            strs.push_back(ss.str());
        }
        return strs;
    }
};