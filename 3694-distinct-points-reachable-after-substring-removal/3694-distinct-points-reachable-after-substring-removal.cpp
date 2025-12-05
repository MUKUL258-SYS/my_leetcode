class Solution {
public:
    int distinctPoints(string s, int k) {
        int x=0;
        int y=0;
        int n=s.size();
        set<pair<int,int>>st;
        for(int i=0;i<k;i++){
            char ch=s[i];
           if(ch=='U')y++;
           else if(ch=='D')y--;
           else if(ch=='R')x++;
           else x--;
        }
        st.insert({x,y});
        for(int i=k;i<n;i++){
           char ch1=s[i-k];
             char ch2=s[i];
           if(ch2=='U')y++;
           else if(ch2=='D')y--;
           else if(ch2=='R')x++;
           else x--;
        if(ch1=='U')y--;
           else if(ch1=='D')y++;
           else if(ch1=='R')x--;
           else x++;
 st.insert({x,y});
        }
       // s.insert({x,y});
        return st.size();
    }
};