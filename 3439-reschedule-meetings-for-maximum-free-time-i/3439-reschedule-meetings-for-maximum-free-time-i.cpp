class Solution {
public:
int helper(int k,vector<int>&v){
    int maxi=0;
    int sum=0;
    int n=v.size();
    for(int i=0;i<k;i++){
        sum+=v[i];
    }
    maxi=sum;
    for(int i=1;i+k<=n;i++){
        sum-=v[i-1];
        sum+=v[i+k-1];
        maxi=max(maxi,sum);
    }
    return maxi;
}
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
        vector<int>v;
        int n=st.size();
        v.push_back(st[0]);
        for(int i=0;i+1<n;i++){
            v.push_back(st[i+1]-et[i]);
        }
        v.push_back(eventTime-et.back());
     //   for(auto i:v)cout<<i<<endl;
        return helper(k+1,v);
    }
};