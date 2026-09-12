class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>follower;
    int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>>feed;
    for (auto fd : follower[userId]) {
        for (auto tweet : tweets[fd]) {
            feed.push_back(tweet);
        }
    }

    // Add my own tweets
    for (auto tweet : tweets[userId]) {
        feed.push_back(tweet);
    }

            sort(feed.begin(), feed.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });
        vector<int>res;

        for(int i=0;i<min(10,(int)feed.size());i++){
            res.push_back(feed[i].second);
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if( followerId !=followeeId)
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};
