class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        //vector<int>occur_c;
        //vector<int>occur_l;
        unordered_map<char,int>mp_c,mp_l;
        for(int i=0;i<n;i++){
          char ch=word[i];
          if(ch>='a'&&ch<='z'){
            mp_l[ch]=i+1;
          }
          else{
            if(mp_c[ch]>0)continue;
            mp_c[ch]=i+1;
          }
        }
        set<char>s;
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(ch>='A'&&ch<='Z'){
               // if(mp.contains)
               if(mp_l[ch+32]==0)continue;
               if(mp_c[ch]>mp_l[ch+32]){
                s.insert(ch);
               }
            }
        }
        return s.size();
    }
};