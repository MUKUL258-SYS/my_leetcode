class Solution {
public:
int helper(vector<int>&v1,vector<int>&v2){
    int maxi1=v1.back();
    int maxi2=v2.back();
    int n=v1.size();
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        int val1=v1[i];
        int val2=v2[i];
        if(v1[i]<=maxi1 && v2[i]<=maxi2)continue;
        else if(val2<=maxi1 && val1<=maxi2){
        cnt++;
        }
        else return INT_MAX;
    }
    return cnt;
}
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int v1=helper(nums1,nums2);
        swap(nums1[n-1],nums2[n-1]);
        int v2=helper(nums1,nums2);
        int v=min(v1,v2);
        if(v==INT_MAX)return -1;
        return min(v1,v2+1);
       // return v==INT_MAX?-1:v;
    }
};