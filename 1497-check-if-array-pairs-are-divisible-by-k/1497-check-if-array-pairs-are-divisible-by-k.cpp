class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>v;
        unordered_map<int,int>mp;
        for(auto i:arr){
      v.push_back((i%k+k)%k);
      mp[(i%k+k)%k]++;
        }
        for(auto i:v)cout<<i<<endl;
        sort(v.begin(),v.end());
        for(auto i:v){
            if(mp[i]==0)continue;
            if(i==0){
                mp[0]--;
                if(mp[0]==0){
                    //cout<<"c1"<<endl;
                    return false;
                }
                mp[0]--;
                continue;
            }
            int r=k-i;
            if(mp[r]==0){
                if(mp[-1*i]>0){
                     r=(-1*i);

                }
                else    return false;
            }
            mp[i]--;
            mp[r]--;


        }
        return true;

    }
};