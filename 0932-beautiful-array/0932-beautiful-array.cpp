class Solution {
public:
    vector<int> beautifulArray(int n) {
      if(n==1){
        return {1};
      }  
      vector<int>l=beautifulArray((n+1)/2);
      vector<int>r=beautifulArray(n/2);
      for(auto &i:l){
        i=2*i-1;
      }
      for(auto &i:r){
        i=i*2;
      }
      l.insert(l.end(),r.begin(),r.end());
      return l;
    }
};