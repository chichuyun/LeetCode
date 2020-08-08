class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;

        vector<pair<pair<int, int>, bool>> buckets;
        int minv = *min_element(nums.begin(), nums.end());
        int maxv = *max_element(nums.begin(), nums.end());

        int bucket_size = max(1, (maxv-minv)/((int)nums.size()-1));
        int bucket_num = (maxv-minv)/bucket_size + 1;
        
        buckets.resize(bucket_num);
        for(auto& p : buckets) {
            p.second = false;
            p.first.first = INT_MAX;
            p.first.second = INT_MIN;
        }
        for(auto&& n : nums) {
            int index = (n-minv)/bucket_size;
            buckets[index].second = true;
            buckets[index].first.first = min(buckets[index].first.first, n);
            buckets[index].first.second = max(buckets[index].first.second, n);
        }

        int prevBucketMax = minv, maxGap = 0;
        for (auto&& bucket : buckets) {
            if (!bucket.second) continue;

            maxGap = max(maxGap, bucket.first.first - prevBucketMax);
            prevBucketMax = bucket.first.second;
        }

        return maxGap;
    }
};