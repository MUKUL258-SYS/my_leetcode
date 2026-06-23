class Solution {
public:
string t;
vector<vector<vector<int>>>v;
int func(int idx){
    vector<vector<int>>vp=v[idx];
    int n=vp.size();
    if(n==0)return 0;
    if(n==1)return vp[0][1]-vp[0][0]+1;
    int maxi=vp[0][1]-vp[0][0]+2;
    for(int i=1;i<n;i++){
        int s0=vp[i-1][0];
     int e0=vp[i-1][1];
     int s1=vp[i][0];
     int e1=vp[i][1];
     int len1=e0-s0+1;
     int len2=e1-s1+1;
     maxi=max(maxi,len2+1);
     if((s1-e0)==2){
        if(i+1<n){
            maxi=max(maxi,len1+len2+1);
        }
        else if(i-2>=0){
            maxi=max(maxi,len1+len2+1);
        }
        else maxi=max(maxi,len1+len2);
     }
    }
    return maxi;
}
vector<vector<int>> helper(char ch){
    int n=t.size();
    vector<vector<int>>res;
    for(int i=0;i<n;i++){
        if(t[i]==ch){
            int j=i;
            while(j<n && t[j]==ch)j++;
           res.push_back({i,j-1});
            i=j-1;
        }
    }
    return res;
}
    int maxRepOpt1(string text) {
       // vector<vector<vector<int>>>v(26);
       v.resize(26);
       t=text;
        for(char ch='a';ch<='z';ch++){
            v[ch-'a']=helper(ch);
        }
        int maxi=0;
        for(int i=0;i<26;i++){
            maxi=max(maxi,func(i));
        }
        return maxi;

    }
};