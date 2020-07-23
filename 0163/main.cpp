class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(upper < lower) return {};

        if(nums.empty()) {
            if(upper==lower) {
                return vector<string>(1,to_string(upper));
            } else {
                return vector<string>(1,to_string(lower)+"->"+to_string(upper));
            }
        }

        vector<string> str;
        ostringstream tmp;
        long low = nums[0];
        if(low > lower) {
            if(low==lower+1) {
                tmp<<lower;
            } else {
                tmp<<lower<<"->"<<low-1;
            }
            if(tmp.str().size()!=0) str.push_back(tmp.str());
            tmp.str("");
        }

        for(int i=1; i<nums.size(); ++i) {
            if((long)nums[i]-nums[i-1]==2) {
                tmp<<nums[i]-1;
            } else if((long)nums[i]-nums[i-1]>2) {
                tmp<<nums[i-1]+1<<"->"<<nums[i]-1;
            }
            if(tmp.str().size()!=0) str.push_back(tmp.str());
            tmp.str("");
        }
        
        low = nums.back();
        if(low < upper) {
            if(low==upper-1) {
                tmp<<upper;
            } else {
                tmp<<low+1<<"->"<<upper;
            }
            if(tmp.str().size()!=0) str.push_back(tmp.str());
            tmp.str("");
        }
        
        return str;
    }
};