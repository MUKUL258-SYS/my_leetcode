class Solution {
public:
    long long minEnergy(int q, int b, vector<vector<int>>& intervals) {
        long long ans=0;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]>res.back()[1]){
                res.push_back(intervals[i]);
            }
            else{
                auto v=res.back();
                int maxi=max(v[1],intervals[i][1]);
                res.pop_back();
                res.push_back({v[0],maxi});
            }
        }
        long long value=ceil(b/(3.0));

        for(auto i:res){
           // cout<<i[0]<<" "<<i[1]<<endl;
            long long m=i[1]-i[0]+1;
            ans+=(value*(m));
        }
        return ans;
    }
};