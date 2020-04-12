class Twitter {
private:
    unordered_map<int, unordered_set<int>> ids;
    forward_list<pair<int,int>> news;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        ids[userId].insert(userId);
        news.emplace_front(userId,tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> nums;
        for(auto &p : news) {
            if(ids[userId].find(p.first)!=ids[userId].end()) {
                nums.push_back(p.second);
            }
            if(nums.size() >= 10) break;
        }
        return nums;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        ids[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(ids[followerId].find(followeeId)!=ids[followerId].end()) {
            if(followerId!=followeeId) {
                ids[followerId].erase(followeeId);
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */