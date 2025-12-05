class Solution {
public:
    int distinctPoints(string s, int k) {
        int n=s.size();
        vector<int>prex(n+1,0),prey(n+1,0),suffx(n+1,0),suffy(n+1,0);
        for(int i=0;i<n;i++){
            prex[i+1]=prex[i];
            prey[i+1]=prey[i];
            char ch=s[i];
            if(ch=='U')prey[i+1]++;
            else if(ch=='D')prey[i+1]--;
            else if(ch=='L')prex[i+1]--;
            else prex[i+1]++;
        }
        for(int i=n-1;i>=0;i--){
            suffx[i]=suffx[i+1];
            suffy[i]=suffy[i+1];
            char ch=s[i];
            if(ch=='U')suffy[i]++;
            else if(ch=='D')suffy[i]--;
            else if(ch=='L')suffx[i]--;
            else suffx[i]++;
        }
        set<pair<int,int>>sm;
        for(int i=0;i<=n-k;i++){
        sm.insert({prex[i]+suffx[i+k],prey[i]+suffy[i+k]});

        }
        return sm.size();
    }
};