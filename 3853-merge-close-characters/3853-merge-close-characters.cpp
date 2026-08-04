class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n=s.size();
        for(int i=0;i<s.size();){
            char ch=s[i];
            int mini=min(i+k+1,(int)s.size());
            int match=-1;
            for(int j=i+1;j<mini;j++){

                if(s[j]==ch && (j-i<=k)){
                    match=j;
                    break;
                    
                }
               
            }
            if(match!=-1){
                s.erase(match,1);
                i=max(0,i-k);
            }else{
                   i++;
            }
        }
        return s;
    }
};