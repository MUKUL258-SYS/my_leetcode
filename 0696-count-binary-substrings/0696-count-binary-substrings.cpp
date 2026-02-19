class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int sum=1;
        vector<int>v;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                sum++;
            }
            else{
               v.push_back(sum);
               sum=1;
            }
        }
        v.push_back(sum);
        int res=0;
        for(int i=1;i<v.size();i++){
           res+=min(v[i],v[i-1]);
        }
        return res;
    }
};