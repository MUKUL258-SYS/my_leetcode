class Solution {
public:
int solver(vector<int>&nums1,vector<int>&nums2,int s1,int s2){
    int n=nums1.size();
    int m=nums2.size();
    if(n>(6*m))return -1;
    int i=n-1;
    int j=0;
    int ops=0;
    //int c1=-1;
   // int c2=-1;
    while(i>=0||j<m){
        if(s1<=s2)break;
    int c1=-1;
    int c2=-1;
   // int diff1=0,diff2=0;
    if(i>=0){
       c1=nums1[i]-1;
    }
    if(j<m){
        c2=6-nums2[j];
    }
    if(c1>=c2){
      s1=s1-nums1[i]+1;
      i--;
    }
    else{
        s2=s2+6-nums2[j];
        j++;
    }
    ops++;
    }
    return ops;
}
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1=0;
        int s2=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(auto i:nums1)s1+=i;
        for(auto i:nums2)s2+=i;
        if(s1<s2)return solver(nums2,nums1,s2,s1);

        return solver(nums1,nums2,s1,s2);
    }
};