class Solution {
public:
    string compressedString(string word) {
        int cnt=1;
        string s="";
        int n=word.size();
        int i;
        for(i=1;i<n;i++){
            if(word[i]==word[i-1]&&cnt<9){
                cnt++;
            }
            else{
               //cnt=min(9,cnt);
               s+=to_string(cnt);
               s+=word[i-1];
               cnt=1;
            }
        }
               //cnt=min(9,cnt);
               s+=to_string(cnt);
               s+=word[i-1];
            return s;
    }
};