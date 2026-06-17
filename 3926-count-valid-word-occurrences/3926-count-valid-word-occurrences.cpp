class Solution {
public:
bool helper(char ch){
    if(ch>='a' && ch<='z')return true;
    return false;
}
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        for(auto &i:chunks){
           s+=(i);
        }
        unordered_map<string,int>mp;
        string temp="";
       int n=s.size();
       for(int i=0;i<n;i++){
        if(s[i]=='-'){
            if(i>0 && i<(n-1)){
                char ch1=s[i-1];
                char ch2=s[i+1];
                if(helper(ch1) && helper(ch2)){
                temp+=s[i];
                }
                else {
                  mp[temp]++;
                  temp="";
                }
            }
            else {
              mp[temp]++;
                  temp="";
            }
        }
        else if(s[i]==32){
              mp[temp]++;
              temp="";
        }
        else{
            temp+=s[i];
        }
       }
       if(temp.size()>0)mp[temp]++;
       vector<int>v;
       /*for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
       }*/
       for(auto i:queries){
         v.push_back(mp[i]);
       }
       return v;
    }
};