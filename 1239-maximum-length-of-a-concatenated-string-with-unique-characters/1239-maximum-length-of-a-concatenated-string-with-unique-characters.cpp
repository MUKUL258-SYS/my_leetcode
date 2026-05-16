class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        int maxi=0;
        for(int mask=1;mask<(1<<n);mask++){
            unordered_map<char,int>mp;
            bool flag=true;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    for(auto ch:arr[i]){
                        mp[ch]++;
                        if(mp[ch]>1){
                            flag=false;
                            break;
                        }
                    }
                    if(!flag)break;
                }
            }
            if(flag)maxi=max(maxi,(int)mp.size());
        }
        return maxi;
    }
};