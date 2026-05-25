class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        long long sum=0;
        int len=0;
        int i;
        for(i=n-1;i>=0;i--){
         int val=s[i]-'0';
         int pos=n-i-1;
         if(pos>=31){
            if(val==0)len++;
            continue;
         }
         sum=sum+(1ll<<pos)*(val);
         if(sum>k)break;
         len++;
         
        }
      //  if(sum>k)len--;
        while(i>=0){
            if(s[i]=='0')len++;
            i--;
        }
        return len;
        
    }
};