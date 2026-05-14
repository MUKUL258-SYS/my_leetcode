class Solution {
public:
int helper(string s){
    stringstream ss(s);
    string word;
    int cnt=0;
    while(ss>>word){
        cnt++;
    }
    return cnt;
}
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n=messages.size();
        //int maxi=0;
        //string res;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            int cnt_words=helper(messages[i]);
            mp[senders[i]]+=cnt_words;

        }
        string res;
        int maxi=0;
        for(auto i:mp){
          if(i.second>maxi){
            maxi=i.second;
            res=i.first;
          }
          else if(i.second==maxi){
            res=max(res,i.first);
          }
        }
        return res;
    }
};