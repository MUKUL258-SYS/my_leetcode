class Solution {
public:
    int maxSubstrings(string word) {
        int n=word.size();
        vector<int>v(26,-1);
        int cnt=0;
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            if(v[idx]!=-1){
                if(i-v[idx]+1>=4){
                  cnt++;
                  for(int i=0;i<26;i++)v[i]=-1;
                }
            }else{
                v[idx]=i;
            }
        }
        return cnt;
        
    }
};