class Solution {
public:
int helper(vector<int>&temp,vector<int>&v){
    int n=temp.size();
    vector<int>v1,v2;
     for(int i=0;i<n;i++){
            if(temp[i]!=v[i]){
                if(v[i]==0)v1.push_back(i);
                else v2.push_back(i);
            }
        }
       
        if(v1.size()!=v2.size())return -1;
        n=v1.size();
        int ans=0;
        for(int i=0;i<n;i++){
          ans+=abs(v1[i]-v2[i]);
        }
        return ans;
}
    int minSwaps(vector<int>& nums) {
       int cnte=0;
       int cnto=0;
       vector<int>temp;
       vector<int>v1,v2;
       vector<int>v;
       for(auto i:nums){
        if(i%2){cnto++;
        }
        else {cnte++;}
        v.push_back(i%2);
       }
       if(abs(cnte-cnto)>1)return -1;
       int i=0;
       int j=0;
       while(i<cnte&&j<cnto){
        temp.push_back(0);
        temp.push_back(1);
        i++;j++;
       }
       if(i!=cnte)temp.push_back(0);
       if(j!=cnto)temp.insert(temp.begin(),1);
        int n=temp.size();

       /* for(int i=0;i<n;i++){
            if(temp[i]!=v[i]){
                if(v[i]==0)v1.push_back(i);
                else v2.push_back(i);
            }
        }
       
        if(v1.size()!=v2.size())return -1;
        n=v1.size();
        int ans=0;
        for(int i=0;i<n;i++){
          ans+=abs(v1[i]-v2[i]);
        }
        return ans;
        */
        int ans=helper(temp,v);
        if(cnto==cnte){
            for(auto &i:v){
                if(i==1)i=0;
                else i=1;
            }
            ans=min(ans,helper(temp,v));
        }
        return ans;
    }
};