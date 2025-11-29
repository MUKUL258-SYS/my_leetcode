class Solution {
public:
    vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {
        int n=l1.size();
        int m=l2.size();
        unordered_map<string,int>mp1,mp2;
        for(int i=0;i<n;i++)mp1[l1[i]]=i+1;
        for(int i=0;i<m;i++)mp2[l2[i]]=i+1;
        int mini=5000;
        vector<string>v;
        for(auto i:l1){
            if(mp1[i]>0&&mp2[i]>0){
                if(mp1[i]+mp2[i]<mini){
                     mini=mp1[i]+mp2[i];
                    v.clear();
                    v.push_back(i);
                }
                 else if(mp1[i]+mp2[i]==mini){
                        v.push_back(i);
                    }
                }
        }
        return v;
    }
};