class Solution {
public:
    string makeLargestSpecial(string s) {
        
        if(s.length()==0){
            return "";            
        }
        vector<string>ans;
        int cnt=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='1')cnt++;
            else if(s[j]=='0')cnt--;
            if(cnt==0){
                 ans.push_back("1"+makeLargestSpecial(s.substr(i+1,j-i-1))+"0");  
                 i=j+1;
            }
        }
        string finalans="";
        sort(ans.begin(),ans.end(),greater<string>());
        for(auto i:ans)finalans+=i;
        return finalans;
        
    }
};