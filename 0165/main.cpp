class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> nums1, nums2;
        version1 += '.';
        version2 += '.';
        ostringstream str;
        for(char s : version1) {
            if(s=='.') {
                nums1.push_back(stoi(str.str()));
                str.str("");
            } else {
                str<<s;
            }
        }
        for(char s : version2) {
            if(s=='.') {
                nums2.push_back(stoi(str.str()));
                str.str("");
            } else {
                str<<s;
            }
        }
        int len = min(nums1.size(),nums2.size());
        for(int i=0;i<len;++i) {
            if(nums1[i]>nums2[i]) {
                return 1;
            } else if(nums1[i]<nums2[i]) {
                return -1;
            }
        }
        if(nums1.size()>nums2.size()) {
            for(int i=nums2.size();i<nums1.size();++i) {
                if(nums1[i]!=0) return 1;
            }
        } else {
            for(int i=nums1.size();i<nums2.size();++i) {
                if(nums2[i]!=0) return -1;
            }
        }
        return 0;
/*
        istringstream ver1(version1);
        istringstream ver2(version2);

        char c;
        int num1, num2;

        while(bool(ver1 >> num1) + bool(ver2 >> num2)) {
            if(num1 > num2)
                return 1;
            if(num1 < num2)
                return -1;
            
            num1 = 0;
            num2 = 0;
            ver1 >> c;
            ver2 >> c;
        }
        return 0;

*/
    }
};