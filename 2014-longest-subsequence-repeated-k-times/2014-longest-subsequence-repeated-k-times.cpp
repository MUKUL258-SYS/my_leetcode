class Solution {
public:
string res="";
bool isSub(string &s, string &t, int k){
      int i=0,j=0;
    int cnt=0;
    int n=s.size();
    int m=t.size();
    for(int i=0;i<n;i++){
        if(s[i]==t[j]){
            j++;
        }
        if(j==m){
            cnt++;
            j=0;
        }
    }
    return cnt>=k;
}


    string longestSubsequenceRepeatedK(string s, int k) {
        string str="";
       vector<int>freq(26,0);
       for(auto &ch:s){
        freq[ch-'a']++;
       }
       for(int i=0;i<26;i++){
        if(freq[i]>=k)str+=(i+'a');
       }
       queue<string>q;
       q.push("");
       string res="";
       while(!q.empty()){
       auto temp=q.front();
       q.pop();
       for(auto &ch:str){
        string next=temp+ch;
        if(isSub(s,next,k)){
            res=next;
            q.push(next);
        }
       }
       }
       return res;
    }
};