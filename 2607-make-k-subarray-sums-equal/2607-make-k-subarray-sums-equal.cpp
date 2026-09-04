class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans=0;
        int n=arr.size();
        int g=gcd(n,k);
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            vector<int>v;
            for(int j=i;j<n;j+=g){
              v.push_back(arr[j]);
              vis[j]=true;
            }
            sort(v.begin(),v.end());
            int m=v.size();
            int mid=v[m/2];
            long long s=0;
            for(auto i:v)s+=abs(i-mid);
            ans+=s;
        }
        return ans;
        
    }
};