class Solution {
public:
    int longestDecomposition(string s) {
        int n=s.size();
        int ans=1;
        deque<char>dq1,dq2;
        for(int i=0;i<(n/2);i++){
          char ch1=s[i];
          char ch2=s[n-i-1];
          dq1.push_back(ch1);
          dq2.push_front(ch2);
          if(dq1==dq2){
            if(i+1==(n-i-1)){
                ans--;
            }
            ans+=2;
            dq1.clear();
            dq2.clear();
          }
        }
        return ans;
    }
};