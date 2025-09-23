class Solution {
public:
bool helper(string s,string t){
   /* unordered_map<char,int>mp1,mp2;
    for(auto i:s)if(i>='A'&&i<='Z')mp1[i]++;
    for(auto i:t)if(i>='A'&&i<='Z')mp2[]
    */
    string a,b;
    for(auto i:s)if(i>='A'&&i<='Z')a+=i;
    for(auto i:t)if(i>='A'&&i<='Z')b+=i;

    int i=0,j=0;
    while(i<s.size()&&j<t.size()){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else i++;
    }
    if(j!=t.size()||(a!=b)){
       cout<<"whell1"<<endl;
       return false;
    }
    vector<int>v1(26,0),v2(26,0);
    for(auto i:s)if(i>='a'&&i<='z')v1[i-'a']++;
    for(auto i:t)if(i>='a'&&i<='z')v2[i-'a']++;
    for(int i=0;i<26;i++)if(v2[i]>v1[i]){
        cout<<"whell2"<<endl;
        return false;

    }
    return true;
}
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>v;
        for(auto i:queries){
            if(helper(i,pattern))v.push_back(true);
            else v.push_back(false);
        }
        return v;
    }
};