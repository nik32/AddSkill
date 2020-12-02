class Twitter {
private:
    /*  1. follows[i] - returns set of all the people, the user_i follows.
        2. tweets[i] - returns all the tweets posted by user_i sorted according to time (tweets[i][0] being least recent and tweets[i][10] being the most recent).
        3. timestamp - for calculating the recentness of a tweet.
        4. Struct TweetInfo - tweet object to be passed in the max_heap. WE need multiple values so that we can determine the next tweet top be inserted after poping a tweet.
    */
    unordered_map<int, unordered_set<int> > follows;//used set so that some cases of validation of query are handled automatically 
    unordered_map<int, vector< pair<int, int> > > tweets;
    int timestamp;
    struct TweetInfo
    {
        int u_ID;//user who posted the tweet. This will helps us to get the next tweet to be pushed to heap 
        int timestamp;//Main element using which out priority_queue will be built
        int tweetIndx;//Index of our current tweet. Again, helps us to get the next tweet to be pushed to heap 
    };    
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int u_ID, int tweetId) {
        if(tweets.find(u_ID) == tweets.end())
            tweets.insert(make_pair(u_ID, vector<pair<int, int>> ()));
        tweets[u_ID].push_back(make_pair(++timestamp,tweetId));
    }
    
    /*Below functor is defined because the priority_queue takes a functor only for custom comparisions. Passing function pointer did not work when tried.
    *Note - [What]functor is a class which acts like a function. 
            [How ]We make a functor by overloading the '()' operator inside the class. Overloading allows the class to be called as a function)*/
    struct Comparator
    {
        bool operator()(const TweetInfo &t1, const TweetInfo &t2)
        {
            return (t1.timestamp < t2.timestamp);
        }
    };
    
    //function for pushing into the heap - used only for making the code cleaner & shorter
    void pushTweetInHeap(priority_queue<TweetInfo, vector<TweetInfo>, Comparator> &max_heap, int u_ID, int tweetIndx)
    {
        TweetInfo tweet = {u_ID, tweets[u_ID][tweetIndx].first, tweetIndx};
        max_heap.push(tweet);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. 
    Complexity - O(klogk) where k is the number of people the user follows*/
    vector<int> getNewsFeed(int u_ID) 
    {
        priority_queue<TweetInfo, vector<TweetInfo>, Comparator> max_heap;
        vector<int> ans(0);
                
        /*Below loop contributes to the complexity. Because for each person (who the user follows), we will 
        build the heap which is O(kLogk) [we are not building a heap from a pre given array. We are building
        it by putting latest tweet of each person (the user follows). So for k persons we put k time in the 
        heap. Putting in heap is O(logk) so doing it k times gives us O(k*logk)]*/
        for(auto i = follows[u_ID].begin(); i != follows[u_ID].end() ; i++)
        {
            if(tweets[*i].size() <= 0)
                continue;
            pushTweetInHeap(max_heap, *i, tweets[*i].size() - 1);//IMPROVEMENT - Alternativly we can just store the tweets in an array. And outside the loop create the the heap so the complexity can be O(n) and also maybe use make_heap instad of priority_queue
        }
        if(tweets[u_ID].size() >= 1)//Check if user himself has also posted any tweets or not
            pushTweetInHeap(max_heap, u_ID, tweets[u_ID].size() - 1);//This is because the tweets posted by user himself can also be visible in the feed. So add his latest tweet.
        
        /*Tweet at the top of heap will be the most recent tweet [heap is a max heap so it will have the largest element (i.e. the tweet with the biggest timestamp) at its root]. And to get the 10 most recent tweets we just build the heap 10 times using the below loop.
        Note - For each person (user follows), we put only their most recent tweet (i.e. the tweet at last indx of user's tweets array) into the max_heap becasue we know rest other will all be smaller thus saving space and time.*/
        for(int i = 1 ; i <= 10 && !(max_heap.empty()) ; i++)
        {
            //remove topmost tweet from heap and add it's tweet id to our ans
            TweetInfo tweet = max_heap.top();//tweet (in this loop) means the ith latest tweet
            max_heap.pop();
            ans.push_back(tweets[tweet.u_ID][tweet.tweetIndx].second);
            
            //Now once we have removed the most recent tweet of let's say person (i), it can happen that his previous tweet is actually the next most recent tweet. So we put his previous tweet in our heap.
            if(tweet.tweetIndx >= 1)
                pushTweetInHeap(max_heap, tweet.u_ID, tweet.tweetIndx - 1);
        }
        
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        // Remember that we can't follow ourselves...
        if(followerId == followeeId)
            return;
        //Due to use of set other cases of no-op are automatically handled 
        if(follows.find(followerId) == follows.end())
            follows.insert(make_pair(followerId, unordered_set<int> ()));
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        //if the followeeID is already not present in our list we don't need to erase it from set.
        if(follows.find(followerId) != follows.end())
            follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(u_ID,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(u_ID);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
