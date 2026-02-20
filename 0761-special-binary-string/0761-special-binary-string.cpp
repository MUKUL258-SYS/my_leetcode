class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt=0,i=0;
        vector<string>vp;
        for(int j=0;j<s.size();j++){
            cnt+=(s[j]=='1')?1:-1;
            if(cnt==0){
                vp.push_back("1"+makeLargestSpecial(s.substr(i+1,j-i-1))+"0");
                i=j+1;
            }
        }
        sort(vp.begin(),vp.end(),greater<string>());
        string res="";
        for(auto i:vp)res+=i;
        return res;

    }
};