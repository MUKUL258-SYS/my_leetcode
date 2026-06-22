class Solution {
public:
int n;
long long helper(vector<int>&nums1,vector<int>&nums2){
    ///transform nums1->nums2;
    vector<vector<long long>>v;
    long long sum=0;
    for(auto i:nums2)sum+=i;
   
    ///kadanes
    int s=0;
    int anss=0;
    int anse=-1;
    long long best=0;
    long long curr=0;
    for(int i=0;i<n;i++){
        long long gain=nums1[i]-nums2[i];
        if(curr+gain<gain){
            curr=gain;
            s=i;
        }
        else{
            curr+=gain;
        }

        if(curr>best){
            best=curr;
          anss=s;
          anse=i;
        }
    }
    if(anse==-1)return sum;
    vector<int>pre1(n,0);
    vector<int>pre2(n,0);
    pre1[0]=nums1[0];
    for(int i=1;i<n;i++){
        pre1[i]=pre1[i-1]+nums1[i];
    }
    pre2[0]=nums2[0];
    for(int i=1;i<n;i++){
        pre2[i]=pre2[i-1]+nums2[i];
    }
      //vector<int>t;
    /*  for(auto i:v){
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
      }
     */
      s=anss;
     int e=anse;
   sum-=(pre2[e]-(s-1>=0?pre2[s-1]:0));
    sum+=(pre1[e]-(s-1>=0?pre1[s-1]:0));
return sum;

}
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
         n=nums1.size();
        vector<vector<int>>v;
      return max(helper(nums1,nums2),helper(nums2,nums1));
       
    }
};