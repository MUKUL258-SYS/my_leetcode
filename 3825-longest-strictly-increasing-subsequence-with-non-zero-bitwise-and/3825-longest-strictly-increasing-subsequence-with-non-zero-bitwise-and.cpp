class Solution {
public:
int lis(vector<int>&vp){
   // int n=nums.size();
    vector<int>res;
    for(auto i:vp){
        if(res.size()==0||i>res.back()){
            res.push_back(i);
        }
        else{
 auto it=lower_bound(res.begin(),res.end(),i);
 *it=i;
        }
    }
    
    return res.size();
}
    int longestSubsequence(vector<int>& nums) {
       
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<=30;i++){
            long long mask=1LL<<i;
            //cout<<mask<<endl;
            vector<int>temp;
            for(auto &num:nums){
                if((mask & num)!=0){
                 temp.push_back(num);
                }
            }
            if(temp.size())maxi=max(maxi,lis(temp));
        }
        return maxi;
    }
};