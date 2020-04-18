class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        vector<int> nums(3,0);
        vector<int> res(requirements.size(), -1), ans(requirements.size(), -3);
        vector<pair<int,int>> f(requirements.size()), s(requirements.size()), t(requirements.size());
        for(int i=0;i<requirements.size();++i) {
            f[i].first = requirements[i][0]; f[i].second = i;
            s[i].first = requirements[i][1]; s[i].second = i;
            t[i].first = requirements[i][2]; t[i].second = i;
        }
        sort(f.begin(),f.end());
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int l=0, m=0, n=0, ll, mm, nn;
        for(int j=0;j<increase.size();++j) {
            nums[0] += increase[j][0]; nums[1] += increase[j][1]; nums[2] += increase[j][2];
            ll = l; mm = m; nn = n;
            for(int i=ll;i<f.size();++i) {
                if(nums[0]>=f[i].first) {
                    ++l;
                    res[f[i].second] = max(res[f[i].second], j+1);
                    ++ans[f[i].second];
                } else {
                    break;
                }
            }
            for(int i=mm;i<s.size();++i) {
                if(nums[1]>=s[i].first) {
                    ++m;
                    res[s[i].second] = max(res[s[i].second], j+1);
                    ++ans[s[i].second];
                } else {
                    break;
                }
            }
            for(int i=nn;i<t.size();++i) {
                if(nums[2]>=t[i].first) {
                    ++n;
                    res[t[i].second] = max(res[t[i].second], j+1);
                    ++ans[t[i].second];
                } else {
                    break;
                }
            }
        }
        for(int i=0;i<res.size();++i) {
            if(ans[i]!=0) res[i] = -1;
        }
        for(int i=0;i<requirements.size();++i) {
            if(requirements[i][0]==0 && requirements[i][1]==0 && requirements[i][2]==0) {
                res[0] = 0;
                break;
            }
        }
        return res;
    }
};