class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>mp,rmp;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:nums){
           if(mp[i]>0&&rmp[i]>0){
            rmp[i]--;
            rmp[i+1]++;
            mp[i]--;
           }
            else if(mp[i]>0){
             int j=i;
             int len=0;
             vector<int>temp;
             while(mp[j]>0){
                temp.push_back(j);
                 len++;
                 mp[j]--;
                 j++;
                 if(len==3)break;
             }
             /*for(auto i:temp){
                cout<<i<<" ";
             }*/
             //cout<<endl;
             if(len<3)return false;
             rmp[j]++;
            }
        }
        for(auto i:mp){
            if(i.second>0)return false;
        }
        return true;

    }
};