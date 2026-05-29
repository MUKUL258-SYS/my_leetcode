class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:nums){
            cout<<i<<" ";
            if(mp[i]>0){
               pq.push(i);
               continue;
            }
            mp[i]++;
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        maxi=max(maxi,mini+n);
        if(mp.size()==n)return 0;
        int ans=0;
        int sz=0;
        maxi=nums.back()+n;
        for(int i=0;i<=maxi;i++){
            //cout<<i<<endl;
            if(sz==n)break;
            
            if(mp[i]>0){
                sz++;
                continue;
            }
            if(pq.size()){

               if(i>pq.top()){ans+=(i-pq.top());
                pq.pop();
                sz++;
               }
            }
        }
        return ans;

    }
};