class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        if(k==0){
            return nums1==nums2?0:-1;
        }
        for(int i=0;i<n;i++){
            if(nums1[i]==nums2[i])continue;
            if((nums1[i]%k)==(nums2[i]%k))continue;
           // if((nums2[i]%k)==nums1[i])continue;

            return -1;
        }
        long long inc=0;
        long long dec=0;
        for(int i=0;i<n;i++){
            if(nums1[i]==nums2[i])continue;
            if(nums1[i]>nums2[i]){
                inc+=((nums1[i]-nums2[i])/k);
            }
            else dec+=((nums2[i]-nums1[i])/k);
        }
        //cout<<inc<<" "<<dec<<endl;
        if(inc==dec)return inc;
        return -1;


    }
};