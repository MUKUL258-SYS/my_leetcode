class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>pre(n,0);
        for(auto i:shifts){
            int s=i[0];
            int e=i[1];
            int dir=i[2];
            if(dir==0){
                pre[s]-=1;
                if(e+1<n)pre[e+1]+=1;
            }
            else{
                pre[s]+=1;
               if(e+1<n)pre[e+1]-=1;
            }
        }
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1];
        }
        /*for(auto i:pre){
            cout<<i<<" ";
        }
        */
        string res="";
        for(int i=0;i<n;i++){
            int shift=pre[i];
            int c=((shift%26)+26)%26;
           //res+=(s[i]+c);
           char ch='a'+(s[i]-'a'+c)%26;
           res+=ch;
        }
        return res;

    }
};