class Solution {
public:
    string convertToTitle(int n) {
        stringstream str;
        while(n) {
            str<<char(65+(n-1)%26);
            n = (n-1)/26;
        }

        string s=str.str();
        reverse(s.begin(),s.end());
        return s;
    }
};