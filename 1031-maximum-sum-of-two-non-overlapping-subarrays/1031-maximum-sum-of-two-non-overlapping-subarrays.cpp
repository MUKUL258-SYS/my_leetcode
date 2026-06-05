class Solution {
public:
int helper(int len1,int len2,vector<int>&pre){
     int maxi=0;
     int n=pre.size();
        for(int i=len1-1;i<n;i++){
            int sub=0;
            if(i-len1>=0)sub=pre[i-len1];
           int sum=pre[i]-sub;
           for(int j=i+len2;j<n;j++){
             int sub2=0;
            if(j-len2>=0)sub2=pre[j-len2];
            int s=(pre[j]-sub2);
            maxi=max(maxi,sum+s);
           }
        }
        return maxi;
}
    int maxSumTwoNoOverlap(vector<int>& nums, int len1, int len2) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        
      return max(helper(len1,len2,pre),helper(len2,len1,pre));
    }
};