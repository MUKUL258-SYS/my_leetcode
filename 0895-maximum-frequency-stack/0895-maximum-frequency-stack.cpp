class FreqStack {
public:
unordered_map<int,int>freq;
unordered_map<int,stack<int>>mp;
int maxfreq;
    FreqStack() {
        maxfreq=0;
    }
    
    void push(int val) {
        freq[val]++;
        mp[freq[val]].push(val);
        maxfreq=max(maxfreq,freq[val]);
    }
    
    int pop() {
        int v=mp[maxfreq].size()?mp[maxfreq].top():0;
        mp[maxfreq].pop();
        freq[v]--;
        if(mp[maxfreq].empty())maxfreq--;
        return v;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */