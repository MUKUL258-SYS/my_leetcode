class Solution {
public:
int k;
int ans;
vector<int>arr;
void dfs(int i,vector<int>&temp){
    int n=arr.size();
     if(i>=n){
   int maxi=0;
        for(auto i:temp){
           maxi=max(maxi,i);
        }
        ans=min(ans,maxi);
        return;
     }

     for(int j=0;j<k;j++){
        temp[j]+=arr[i];
        dfs(i+1,temp);
        temp[j]-=arr[i];
        if(temp[j]==0)break;
     }
}
    int distributeCookies(vector<int>& cookies, int k) {
        this->k=k;
        arr=cookies;
        ans=INT_MAX;
        vector<int>temp(k,0);
        dfs(0,temp);
        return ans;
    }
};