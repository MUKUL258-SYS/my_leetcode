class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto i:tasks){
            
            mp[i]++;
        }
        for(auto i:mp){
            int f=i.second;
            if(f==1)return -1;
            int val=f/3;
            if(f%3==0)ans+=val;
            else{
                ans+=(val+1);
            }
        }
        return ans;

    }
};