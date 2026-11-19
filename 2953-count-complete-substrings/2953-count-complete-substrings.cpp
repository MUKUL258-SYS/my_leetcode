class Solution {
public:
int k; 
bool checker(vector<int>&freq,int len){
    int ct=0;
    for(int i=0;i<26;i++){
        if(freq[i]==0)continue;
        if(freq[i]!=k)return false;
        ct++;
       // if(ct>len)return false;
    }
    //if(ct>len)return false;
    return true;
}
int helper(string s,int k){
int ans=0;
int tl=s.size();
    for(int len=1;len<=26;len++){
           int swl=len*k;
            if(swl>tl)break;
           vector<int>freq(26,0);
           for(int i=0;i<swl;i++){
            freq[s[i]-'a']++;
           }
           if(checker(freq,len))ans++;
           for(int i=1;i+swl<=tl;i++){
            freq[s[i-1]-'a']--;
            freq[s[i+swl-1]-'a']++;
            if(checker(freq,len))ans++;
           }
    }
    return ans;
}
    int countCompleteSubstrings(string word, int k) {
        int last=0;
        long long ans=0;
        this->k=k;
        string str="";
        str+=word[0];
        for(int i=1;i<word.size();i++){
            if(abs(word[i]-word[i-1]) > 2){
              ans+=helper(str,k);
              str="";
              last=i;
            }
            str+=word[i];
        }
        ans += helper(str,k);
        return ans;
    }
};