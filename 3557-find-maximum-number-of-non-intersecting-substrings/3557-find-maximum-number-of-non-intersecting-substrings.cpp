class Solution {
public:
    int maxSubstrings(string word) {
        unordered_map<char,int>mp;
        int n=word.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mp[word[i]]==0){
                //cout<<i<<endl;
                mp[word[i]]=i+1;
            }
            else{
               int v=mp[word[i]];
               v--;
               if((i-v+1)>=4){
                //cout<<i<<" "<<v<<endl;
                mp.clear();
               // mp[word[i]]=i+1;
                cnt++;
               }

            }
        }
        return cnt;

    }
};