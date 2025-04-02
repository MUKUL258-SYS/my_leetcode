class SummaryRanges {
public:
set<int>s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        int start=-1;
        int end=-1;
        for(auto i:s){
            if(end<0){
                start=end=i;
            }
            else if(i-end == 1){
                   end=i;
            }
            else{
                 ans.push_back({start,end});
                 start=end=i;
            }
        }
          if(start==-1||end==-1)return ans;
          ans.push_back({start,end});
          return ans;
    }
};
