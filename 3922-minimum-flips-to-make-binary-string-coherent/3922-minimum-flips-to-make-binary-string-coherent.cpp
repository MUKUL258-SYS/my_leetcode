class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        if(n<=2)return 0;
       
      
        int cnt1=0;
        int cnt0=0;
        for(auto i:s){
            if(i=='0')cnt0++;
            else cnt1++;
        }
        int mini=n+1;
        mini=min(mini,n-cnt1);
        mini=min(mini,n-cnt0);
        for(int i=0;i<n;i++){
            //int value=s[i]=='1'?-1:0;
            if(s[i]=='1'){
                mini=min(mini,cnt1-1);
            }
            else{
              mini=min(mini,cnt1);
            }


        }
        int cnt=0;
        for(int i=1;i<n-1;i++){
        if(s[i]=='1')cnt++;
        }
        if(s[0]=='0')cnt++;
        if(s[n-1]=='0')cnt++;
        mini=min(mini,cnt);
        return mini;

    }
};