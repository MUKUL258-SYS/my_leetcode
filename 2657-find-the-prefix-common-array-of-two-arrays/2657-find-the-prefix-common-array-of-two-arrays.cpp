class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
         vector<int>v;
         unordered_map<int,int>mp1,mp2;
        for(int i=0;i<n;i++){
            mp1[A[i]]++;
         mp2[B[i]]++;
           int cnt=0;
         for(auto i:mp1)if(mp2[i.first]>0)cnt++;
         v.push_back(cnt);
         //mp1[A[i]]++;
        // mp2[B[i]]++;
        }
        return v;
    }
};