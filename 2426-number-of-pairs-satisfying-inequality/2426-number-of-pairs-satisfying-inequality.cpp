class Solution {
public:
long long ans;
int diff;
void mergesort(int l,int r,vector<int>&res){
    if(l>=r)return ;
    int mid=(l+r)/2;
    mergesort(l,mid,res);
    mergesort(mid+1,r,res);
    int j=mid+1;
    for(int i=l;i<=mid;i++){
        while(j<=r && res[i]>res[j]+diff)j++;
        ans+=(r-j+1);
    }
    int i=l;
     j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=r){
        if(res[i]<=res[j]){
            temp.push_back(res[i]);
            i++;
        }
        else {temp.push_back(res[j]);
           j++;
        }
    }
    while(i<=mid){
        temp.push_back(res[i]);
            i++;
    }
     while(j<=r){
        temp.push_back(res[j]);
            j++;
    }
    for(int k=0;k<temp.size();k++){
        res[l+k]=temp[k];
    }
    
}
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
         ans=0;
         this->diff=diff;
         vector<int>v;
         int n=nums1.size();
         for(int i=0;i<n;i++){
            v.push_back(nums1[i]-nums2[i]);
         }
         mergesort(0,n-1,v);
         return ans;
        
    }
};