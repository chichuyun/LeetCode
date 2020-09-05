class Codec {
private:
    unsigned int base = 9999;
    unsigned int str2num(string str) {
        return atoi(str.c_str());
    }

    string num2str(unsigned int num) {
        string str = to_string(num);
        if(str.size() < 4) {
            if(str.size()==3) {
                str = "0" + str;
            } else if(str.size()==2) {
                str = "00" + str;
            } else if(str.size()==1) {
                str = "000" + str;
            }
        }
        return str;
    }
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        ostringstream str;
        for(string& s : strs) {
            int len = s.size();
            if(len == 0) {
                str << "00000";
            }
            int i = 0;
            while(len > 0) {
                if(len <= base) {
                    str << "0" << num2str(len) << s.substr(i,len); 
                } else {
                    str << "1" << s.substr(i,base);
                }
                len -= base;
                i += base;
            }
        }
        return str.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0, k = 0;
        while(i < s.size()) {
            ostringstream str;
            while(s[i]=='1') {
                ++i;
                str << s.substr(i,base);
                i += base;
            }
            int len = str2num(s.substr(i+1,4));
            i += 5;
            str << s.substr(i,len);
            i += len;
            strs.push_back(str.str());
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));