class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>>v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double val=((1.0*arr[i])/arr[j]);
                v.push_back({val,{arr[i],arr[j]}});
            }
        }
        sort(v.begin(),v.end());
        if(v.size()<k)return {};
        return {v[k-1].second.first,v[k-1].second.second};
    }
};