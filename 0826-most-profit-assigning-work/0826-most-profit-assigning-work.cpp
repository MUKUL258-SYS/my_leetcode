class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n=d.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
           v.push_back({d[i],p[i]});
        }
        sort(v.begin(),v.end());
        for(int i=1;i<n;i++){
            if(v[i].second < v[i-1].second){
                v[i].second = v[i-1].second;
            }
        }
        long long ans=0;
        for(auto i:w){
            //lower_bound(v.begin(),v.end(),)
           auto idx=upper_bound(v.begin(),v.end(),make_pair(i,INT_MAX))-v.begin();
           idx--;
           if(idx>=0)ans+=v[idx].second;
        }
        return ans;


    }
};