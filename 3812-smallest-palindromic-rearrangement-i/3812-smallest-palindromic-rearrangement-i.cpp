class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        for(auto i:s)mp[i]++;
        string res="";
        char last='A';
         for(auto i:mp){
            if((i.second%2)==1)last=i.first;
            int times=i.second;
            times/=2;
            while(times--){
                res+=(i.first);
            }
         }
         cout<<res<<endl;
        string t=res;
        reverse(t.begin(),t.end());
        if(last!='A'){
            res+=last;
        }
        res+=t;
         
         

         return res;
    }
};