class Solution {
public:
string  helper(int n){
    string s="";
    while(n){
        if(n%2)s+='1';
        else s+='0';
        n/=2;
    }

    reverse(s.begin(),s.end());
    return s.empty() ? "0" : s;
}
    int maxGoodNumber(vector<int>& nums) {
        vector<string>v;
        for(auto i:nums){
            v.push_back(helper(i));
        }
        int n=v.size();
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        vector<string>res;
       for(int i=0;i<n;i++){
          if(i+2<n){
             res.push_back(v[i]+v[i+1]+v[i+2]);
             res.push_back(v[i]+v[i+2]+v[i+1]);
          }
          else if(i-1>=0&&i+1<n){
            res.push_back(v[i]+v[i-1]+v[i+1]);
            res.push_back(v[i]+v[i+1]+v[i-1]);
          }
          else if(i-2>=0){
            res.push_back(v[i]+v[i-2]+v[i-1]);
            res.push_back(v[i]+v[i-1]+v[i-2]);
          }
       }
       sort(res.begin(),res.end(),greater<string>());
       string s=res[0];
    for(auto i:res)cout<<i<<" ";
    cout<<endl;
       int ans=0;
       int j=0;
       for(int i=s.size()-1;i>=0;i--){
             ans=ans+(1<<j)*(s[i]=='1'?1:0);
             j++;
       }
       return ans;

    }
};