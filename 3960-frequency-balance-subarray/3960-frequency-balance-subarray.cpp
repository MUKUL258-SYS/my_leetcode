class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>freq;
            unordered_map<int,int>mp;
            set<int>s;
            for(int j=i;j<n;j++){
                int old_freq=mp[nums[j]];
                if(old_freq>0){
                   // std::erase(freq[old_freq],nums[j]);
                   freq[old_freq]--;
                   if(freq[old_freq]==0)freq.erase(old_freq);
                }
               
              mp[nums[j]]++;
              int new_freq=mp[nums[j]];
              s.insert(nums[j]);
              //freq[new_freq].push_back(nums[j]);
              freq[new_freq]++;
              if(freq.size()==2){
                auto it=freq.begin();
                int f1=it->first;
                it++;
                int f2=it->first;
                int df1=2*f1;
                int df2=2*f2;
                if((f1==df2) || (f2==df1)){maxi=max(maxi,j-i+1);
                  //cout<<i<<" "<<j<<endl;
                }

              }
              if(s.size()==1)maxi=max(maxi,j-i+1);
            }
           
        }
        return maxi;
    }
};