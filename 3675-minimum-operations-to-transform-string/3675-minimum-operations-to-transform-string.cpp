class Solution {
public:
    int minOperations(string s) {
      int maxi=0;
      int cnt=0;
      for(auto i:s){
        if(i=='a')continue;
         cnt++;
        maxi=max(maxi,('z'-i));
      }  
      return cnt>0?maxi+1:0;
    }
};