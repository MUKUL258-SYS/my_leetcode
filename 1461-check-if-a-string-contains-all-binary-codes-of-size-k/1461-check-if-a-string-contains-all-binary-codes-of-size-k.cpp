class Solution {
public:

    bool hasAllCodes(string s, int k) {
        
       unordered_map<string,int> mp;
        string temp;
        int n=s.size();
       for(int i=0;i+k-1<n;i++){
        temp=s.substr(i,k);
        mp[temp]++;
       }
     long long value=pow(2,k);
     long long m=mp.size();
     if(m==value)return true;
     else return false;  
        
    }
};