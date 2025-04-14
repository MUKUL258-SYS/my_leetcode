class Solution {
public:
bool helper(vector<int>&arr,double hr,int mid){
    double ans=0;
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        ans+=ceil((double)arr[i]/mid);
    }
    ans+=((double)arr.back()/mid);
    return ans<=hr;
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s=1;
        int e=1e7;
        int ans=-1;
        while(s<=e){
            int mid=e+(s-e)/2;
            if(helper(dist,hour,mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
       return ans;
    }
};