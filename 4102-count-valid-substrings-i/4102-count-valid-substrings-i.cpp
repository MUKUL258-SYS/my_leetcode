class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans=0;
        long long cnt=0;
        int n=s.size();
        int e=0;
        for(int i=0;i<n;i++){
          if(i+2<n && s.substr(i,3)=="abc"){
            cnt+=2;
            ans+=(cnt*(cnt+1))/2;
            //ans++;
            cnt=0;
            e++;
            //cnt=0;
          }
          else cnt++;
        }
          ans+=(cnt*(cnt+1))/2;
          return ans-e;

       
    }
};