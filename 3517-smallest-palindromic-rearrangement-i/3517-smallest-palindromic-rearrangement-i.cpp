class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1 || n==2)return s;
        map<char,int>mp;
        for(auto ch:s)mp[ch]++;
        vector<char>v(n);
        int i=0;
        int j=n-1;
        for(auto k:mp){
            char ch=k.first;
            int freq=k.second;
         if(freq%2){
            v[n/2]=ch;
            freq--;
         }
         
         while(freq>0 && i<j){
            v[i]=ch;
            v[j]=ch;
            i++;
            j--;
            freq-=2;
         }
        }
        string str="";
        for(auto i:v)str+=i;
        return str;

    }
};