class Solution {
public:
int k;
bool helper(int mid,vector<int>&nums){
    int n=nums.size();
    int cnt=1;
    int last=0;
    for(int i=0;i<n;i++){
        if(nums[i]-nums[last]>=mid){
            last=i;
            cnt++;
        }
    }
    return cnt>=k;
}
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        this->k=k;
        int e=price.back()-price[0];
        int ans=0;
        int s=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(helper(mid,price)){
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