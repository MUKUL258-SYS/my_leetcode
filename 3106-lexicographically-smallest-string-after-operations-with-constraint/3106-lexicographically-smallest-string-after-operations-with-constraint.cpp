class Solution {
public:
    string getSmallestString(string s, int k) {
        if(k==0)return s;
        int i=0;
        int n=s.size();
        string res="";
        for(;i<n;i++){
            char ch=s[i];
            int steps='z'-ch+1;
            steps=min(steps,ch-'a');
            if(steps<=k){
                k-=steps;
                res+='a';
            }
            else{
             res+=(ch-k);
             break;
            }
            if(k==0)break;
        }

        if(i+1<n)res+=s.substr(i+1);
        return res;
    }
};