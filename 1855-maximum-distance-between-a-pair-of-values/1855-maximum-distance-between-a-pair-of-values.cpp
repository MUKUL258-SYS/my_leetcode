class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        reverse(nums2.begin(),nums2.end());
        int m=nums2.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            auto idx=std::lower_bound(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
          // cout<<i<<idx<<endl;
               // idx=idx-nums2.begin();
             // int j=idx-nums2.begin();
             if(idx==nums2.size())continue;
                   int act_idx=m-1-idx;
                    maxi=max(maxi,act_idx-i);
                   
                }
            
            return maxi;
            

        }
};