class Solution {
public:
int ans;
unordered_map<int,int>mp;
vector<string>words;
void dfs(int idx,vector<int>&a,vector<int>&b){
    if(idx>=words.size()){
       bool f=true;
       int s=0;
       for(int i=0;i<a.size();i++){
        if(b[i]>a[i]){
            f=false;
            break;
        }
        s+=(b[i]*mp[i]);
       }
       if(f){
        ans=max(ans,s);
       }
       return ;
    }
    // inc=0,exc=0;
    dfs(idx+1,a,b);
    for(auto word:words[idx]){
        b[word-'a']++;
    }
    dfs(idx+1,a,b);
      for(auto word:words[idx]){
        b[word-'a']--;
    }

    

}
//vector<int>a,b;
/*map<string,int>mp;
unordered_map<char,int>mp2,mp3;
vector<string>words;
vector<char>letters;
int dfs(int i ){
    //problem is can we take this word or not
    //base case
    if(i>=words.size())return 0;
    int inc=0,exc=0;
    exc=dfs(i+1);
    string word=words[i];
    bool flag=true;
    unordered_map<char,int>m=mp3;
    int score=0;
    for(auto i:word){
        if(m[i]<=0){
           flag=false;
           break;
        }
        score+=mp2[i];
        m[i]--;
    }
    if(flag){
         inc=score+dfs(i+1);
    }
 return max(inc,exc);
}
*/
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
      /*  int n=score.size();
        this->words=words;
        this->letters=letters;
        for(auto i:words)mp[i]++;
        for(int i=0;i<n;i++){
            mp2['a'+i]=score[i];
        }
        for(auto i:letters){
            mp3[i]++;
        }
        
    return dfs(0);
    */
    ans=0;
    vector<int>a(26,0),b(26,0);
    this->words=words;
  for(auto i:letters){
    a[i-'a']++;
  }
  for(int i=0;i<=25;i++){
    mp[i]=score[i];
  }
  dfs(0,a,b);
  return ans;
    }
};