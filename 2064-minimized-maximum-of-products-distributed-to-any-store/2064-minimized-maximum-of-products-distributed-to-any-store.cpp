class Solution {
public:
int res;
bool helper(int mid,vector<int>&v,int n){
    int cnt=0;
    for(auto i:v){
        cnt+=(i/mid);
        if(i%mid)cnt++;
        if(cnt>n)return false;
    }
    return cnt<=n;
    
}
    int minimizedMaximum(int n, vector<int>& v) {
        int s=1;
        int e=*max_element(v.begin(),v.end());
        int maxi=e;
        while(s<=e){
            int mid=(s+e)/2;
            if(helper(mid,v,n)){
               // maxi=max(maxi,mid);
               maxi=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return maxi;
    }
};