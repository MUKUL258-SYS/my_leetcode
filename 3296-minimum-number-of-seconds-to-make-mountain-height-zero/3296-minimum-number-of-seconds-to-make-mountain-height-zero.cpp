class Solution {
public:
bool helper(long long v,int h,vector<int>&wT){
    int value=0;
    int total=0;
    for(auto wt:wT){
        int s=0;
        int e=1e6+1;
        int best=s;
        while(s<=e){
            int mid=(s+e)/2;
            if(1ll*wt*(mid)*(mid+1)/2<=v){
              s=mid+1;
            best=mid;
            }
            else{
            e=mid-1;
            }
        }
        total+=best;
        if (total >= h) return true;

    }
    return total>=h;
}
    long long minNumberOfSeconds(int h, vector<int>& wT) {
        long long s=0;
        long long e=1e18;
        long long ans=0;
        while(s<=e){
            long long mid=(s+e)/2;
            if(helper(mid,h,wT)){
                e=mid-1;
                ans=mid;

            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};