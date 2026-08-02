class Solution {
public:
bool helper(int rem,int mini,vector<int>&nums){
    for(auto i:nums){
        if(i%2 == rem)continue;
        if(mini>=i)return false;
    }
    return true;
}

    bool uniformArray(vector<int>& nums1) {
         int cnto=0;
        int cnte=0;
        int n=nums1.size();
        if(n==1)return true;
        int minie=INT_MAX;
        int minio=INT_MAX;

        for(auto i:nums1){
            if(i%2==1){cnto++;
              minio=min(minio,i);
            }
            else { cnte++;
               minie=min(minie,i);
            }
        }
        if(cnte==n || cnto==n)return true;
      //  return false;
        return helper(1,minio,nums1)||helper(0,minio,nums1);
        
        
    }
};