class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
        long long s=0;
        long long e=1e5;
        long long ans=0;
        while(s<=e){
            long long mid=(s+e)/2;
            if((mid*(mid+1))<=2*n){
               ans=max(ans,mid);
               s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};