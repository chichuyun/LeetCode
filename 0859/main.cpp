class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size() || A.size()<=1) return false;
        
        vector<int> nums;
        for(int i=0;i<A.size();++i) {
            if(A[i]!=B[i]) {
                nums.push_back(A[i]);
                nums.push_back(B[i]);
            }
            if(nums.size()>4) return false;
        }

        if(nums.size()==4) {
            if(nums[0]==nums[3] && nums[1]==nums[2]) {
                return true;
            } else {
                return false;
            }
        } else if(nums.size()==2) {
            return false;
        }

        unordered_map<char,int> indexs;
        for(int i=0;i<A.size();++i) {
            if(indexs[A[i]]) return true;
            ++indexs[A[i]];
        }
        return false;
    }
};