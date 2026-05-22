class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        unordered_map<string,int>mp;
        for(auto i:arr1){
            string s=to_string(i);
            for(int j=1;j<=s.size();j++){
                mp[s.substr(0,j)]++;
            }
        }
        int maxi=0;
        for(auto i:arr2){
            string s=to_string(i);
            for(int j=1;j<=s.size();j++){
                string t=s.substr(0,j);
       if(mp[t]>0)maxi=max(maxi,(int)t.size());
            }
        }
        return maxi;
        
    }
};