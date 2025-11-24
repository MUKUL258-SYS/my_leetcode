class Solution {
public:
    vector<string> partitionString(string s) {
        int n=s.size();
        map<string,int>mp;
          vector<string>v;
        for(int i=0;i<n;i++){
            int j=i;
            string temp="";
            while(j<n){
          temp+=s[j];
          if(!mp.count(temp)){
            mp[temp]++;
            v.push_back(temp);
            break;
          }
          j++;
            }
            i=j;

        }
       
        return v;
    }
};