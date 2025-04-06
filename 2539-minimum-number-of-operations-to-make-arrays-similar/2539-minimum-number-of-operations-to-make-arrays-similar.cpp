class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
      //  long long ans=0;
        vector<int>v1,v2,v3,v4;
        for(auto i:nums){
            if(i%2==0)v1.push_back(i);
            else v2.push_back(i);
        }
        for(auto i:target){
            if(i%2==0)v3.push_back(i);
            else v4.push_back(i);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end());
        sort(v4.begin(),v4.end());
        int n=v1.size();
        int m=v4.size();
        long long s1=0,s2=0;
        for(int i=0;i<n;i++){
             if((v3[i]-v1[i])>0){
                s1+=(v3[i]-v1[i]);
             }
        }

         for(int i=0;i<m;i++){
             if((v4[i]-v2[i])>0){
                s2+=(v4[i]-v2[i]);
             }
        }
        return (s1/2)+(s2/2);
    }
};