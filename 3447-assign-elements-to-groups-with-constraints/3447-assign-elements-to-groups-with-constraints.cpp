class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int,int>mp;
        int n=elements.size();
        for(int i=0;i<n;i++){
           if(!mp.count(elements[i]))mp[elements[i]]=i+1;
        }
        vector<int>v;
        for(auto i:groups){
            int mini=INT_MAX;
            for(int j=1;j*j<=i;j++){
                if((i%j)==0){
                 if(mp[j]>0)mini=min(mini,mp[j]-1);
                 if(mp[i/j]>0)mini=min(mini,mp[i/j]-1);
                }
                
            }
            if(mini==INT_MAX)v.push_back(-1);
            else v.push_back(mini);
        }
        return v;
    }
};