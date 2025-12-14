class ExamTracker {
public:
vector<pair<long long,long long>>v;
    ExamTracker() {
        v.push_back({0,0});
    }
    
    void record(int time, int score) {
        auto p=v.back();

       v.push_back({time,p.second+1ll*score});
    }
    
    long long totalScore(int s, int e) {
        //apply lower bound on first value such first value is just small or equal to s-1
        //apply lower bound on first value for e as well such tht first value is just small to eaual to e;
        //auto itr1=lower_bound(v.begin(),v.end(),)
        auto itr1=lower_bound(v.begin(),v.end(),make_pair(s,INT_MIN));
        long long s1=0;
        if(itr1!=v.begin()){
            itr1--;
           s1=itr1->second;
        }
        long long s2=0;
        auto itr2=lower_bound(v.begin(),v.end(),make_pair(e+1,INT_MIN));
        if(itr2!=v.begin()){
            itr2--;
            s2=itr2->second;
        }
        return s2-s1;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */