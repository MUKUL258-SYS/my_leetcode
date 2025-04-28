class Solution {
public:
int target;
int helper(vector<int>&nums,int mid){
     int sum=0;
     for(auto i:nums){
        sum+=min(i,mid);
     }
     return abs(sum-target);
}
    int findBestValue(vector<int>& arr, int target) {
        this->target=target;
        int s=0;
        int e=target;
        while(s<e){
            int mid=(s+e)/2;
            if(helper(arr,mid)<=helper(arr,mid+1)){
                e=mid;
            }
            else s=mid+1;
        }
        return s;
    }
};