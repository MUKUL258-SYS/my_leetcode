class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans=1;
        int diff=INT_MAX;
        int n=nums1.size();
        int val=nums2[n];
        bool f=true;
        int change=INT_MAX;
        for(int i=0;i<n;i++){
           int l=min(nums1[i],nums2[i]);
           int r=max(nums1[i],nums2[i]);
           if(val>=l&&val<=r){
             f=false;
           }
           else{
              change=min(change,min(abs(l-val),abs(r-val)));
           }
        }
        //diff++;
        //ans+=diff;
        cout<<ans<<endl;
        for(int i=0;i<n;i++){
            //diff+=(min(nums2[i]%nums1[i],nums1[i]%nums2[i]));
            ans+=(abs(nums1[i]-nums2[i]));
        }
        if(!f)return ans;
        return ans+change;
    }
};