class TweetCounts {
public:
unordered_map<string,map<int,int>>mp;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval;
        if(freq=="minute")interval=60;
        else if(freq=="hour")interval=3600;
        else interval=3600*24;
        vector<int>v((endTime-startTime)/interval+1,0);
        const auto end=mp[tweetName].upper_bound(endTime);
        for(auto it=mp[tweetName].lower_bound(startTime);it!=end;it++){
            v[(it->first-startTime)/interval]+=it->second;
        }
        return v;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */