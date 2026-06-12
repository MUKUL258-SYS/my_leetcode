class Solution {
public:
vector<int>helper(string s,string t){
    int len=t.size();
 vector<int>v;
    int n=s.size();
    for(int i=0;i+len<=n;i++){
        if(s.substr(i,len)==t){
           // q.push(i);
           v.push_back(i);
        }
    }
    return v;
}
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n=s.size();
       // vector<int>v1=helper(s,a);
        vector<int>v2=helper(s,b);
       for(auto i:v2)cout<<i<<" ";
   //     cout<<endl;
        int len1=a.size();
        int len2=b.size();
        vector<int>res;
        int m=v2.size();
     for(int i=0;i<n;i++){
        if(s.substr(i,len1)==a){
            int idx=upper_bound(v2.begin(),v2.end(),i)-v2.begin();
          // idx--;
          cout<<idx<<endl;
         //  cout<<v2[idx]<<endl;
           if(idx-1>=0){
            if(abs(i-v2[idx-1])<=k){
              res.push_back(i);
              continue;
            }
           }
           if(idx<m){
             if(abs(i-v2[idx])<=k){
              res.push_back(i);
            }
           }
        }
     }
     return res; 
    }
};