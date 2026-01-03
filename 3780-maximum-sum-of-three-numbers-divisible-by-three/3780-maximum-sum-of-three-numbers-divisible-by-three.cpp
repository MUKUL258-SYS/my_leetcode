class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(auto i:nums){
             mp[i%3].push_back(i);
        }
        vector<int>a,b,c;
        a=mp[0];
        b=mp[1];
        c=mp[2];
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        sort(c.begin(),c.end(),greater<int>());
      /*  cout<<"a"<<endl;
        for(auto i:a){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"b"<<endl;
           for(auto i:b){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"c"<<endl;
           for(auto i:c){
            cout<<i<<" ";
        }
        cout<<endl;
        */
        int maxi=0;
        if(c.size()>=3){
          maxi=max(maxi,c[0]+c[1]+c[2]);
        }
        if(a.size()>=3){
          maxi=max(maxi,a[0]+a[1]+a[2]);
        }
         if(b.size()>=3){
          maxi=max(maxi,b[0]+b[1]+b[2]);
        }
        if(b.size()&&a.size()&&c.size()){
            maxi=max(maxi,a[0]+b[0]+c[0]);
        }
        return maxi;
            
    }
};