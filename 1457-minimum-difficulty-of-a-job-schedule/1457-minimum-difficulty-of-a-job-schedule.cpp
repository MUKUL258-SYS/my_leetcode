class Solution {
public:
int t[301][11];
int n;
int dfs(vector<int>&arr,int idx,int d){
    if(d==1)return *max_element(begin(arr)+idx,end(arr));
    if(t[idx][d]!=-1)return t[idx][d];
    int maxi=-1;
    int res=INT_MAX;
    for(int i=idx;i<=n-d;i++){
        maxi=max(maxi,arr[i]);
       res=min(res,maxi+dfs(arr,i+1,d-1));
    }
    return t[idx][d]=res;
}
    int minDifficulty(vector<int>& arr, int d) {
         n=arr.size();
        if(n<d)return -1;
   memset(t,-1,sizeof(t));
   return dfs(arr,0,d);
    }
};