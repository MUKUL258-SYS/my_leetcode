class RangeFreqQuery {
public:
 unordered_map<int,vector<int>>mp;
    RangeFreqQuery(vector<int>& arr) {
       // unordered_map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
       const  vector<int>& v=mp[value];
        auto idx1=lower_bound(v.begin(),v.end(),left)-v.begin();
        auto idx2=upper_bound(v.begin(),v.end(),right)-v.begin();
        idx2--;
        return idx2-idx1+1;

    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */