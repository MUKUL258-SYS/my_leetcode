class Solution {
public:
int kadane(vector<int>&arr,int k){
    if(k==2){
        vector<int>v=arr;
        v.insert(v.end(),arr.begin(),arr.end());
        arr=v;
    }
    int n=arr.size();
    int maxi=0;
    int sum=0;
    for(int i=0;i<n;i++){
   sum+=arr[i];
   maxi=max(maxi,sum);
   if(sum<0)sum=0;
    }
    return maxi;
}
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(k==1){
            return kadane(arr,1);
        }
        int mod=1e9+7;
        int sum=0;
        for(auto i:arr)sum=(sum+i)%mod;
       int v1=kadane(arr,2)%mod;
       return max(1ll*v1,((1ll*(k-2)*sum)%mod+v1)%mod);
    }
};