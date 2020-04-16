struct pair_hash {
    size_t operator()(pair<long double,long double> p) const {
        return hash<long double>()(p.first) ^ hash<long double>()(p.second);
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.empty() || points[0].empty()) return 0;
        unordered_map<pair<long double,long double>, pair<int,int>, pair_hash> nums;
        sort(points.begin(),points.end());
        long double len = numeric_limits<long double>::max();
        int count, count0, k, n, i = 0, j;
        pair<long double,long double> num;
        while(i < points.size()) {
            k = i + 1;
            while(k<points.size() && points[i][0]==points[k][0] && points[i][1]==points[k][1]) ++k;
            count = k - i;
            unordered_set<pair<long double,long double>, pair_hash> sets;
            j = k;
            while(j < points.size()) {
                n = j + 1;
                while(n<points.size() && points[j][0]==points[n][0] && points[j][1]==points[n][1]) ++n;
                count0 = n - j;
                if(points[i][0] == points[j][0]) {
                    num.first = len;
                    num.second = points[i][0];
                } else {
                    num.first = ((long double)points[j][1] - points[i][1])/
                                ((long double)points[j][0] - points[i][0]);  // k
                    num.second = points[i][1] - points[i][0]*num.first; // b
                }
                if(nums.find(num)==nums.end()) {
                    nums[num].first = count + count0;
                    nums[num].second = 1;
                    sets.insert(num);
                } else if(nums[num].second) {
                    nums[num].first += count0;
                }
                j = n;
            }
            for(auto &s : sets) nums[s].second = 0;
            i = k;
        }
        for(auto &p : nums) {
            count = max(count, p.second.first);
        }
        return count;
    }
};