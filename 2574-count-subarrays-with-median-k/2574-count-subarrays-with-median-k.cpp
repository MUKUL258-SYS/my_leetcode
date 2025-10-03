class Solution {
public:
    int countSubarrays(vector<int>& v, int k) {
    int idx=-1;
    int n=v.size();
    for(int i=0;i<n;i++){
        if(v[i]==k){
            idx=i;
            v[i]=0;
        }
        else if(v[i]>k){
            v[i]=1;
        }
        else v[i]=-1;
    } 
    if(idx==-1)return 0;
    unordered_map<int,int>mp;
    mp[0]=1;
    int sum=0;
    for(int i=idx-1;i>=0;i--){
     sum+=v[i];
     mp[sum]++;
    }
    int res=0;
    sum=0;
    for(int i=idx;i<n;i++){
          sum+=v[i];
          res+=mp[-sum];
          res+=mp[-sum+1];
    } 
    return res;
    }
};