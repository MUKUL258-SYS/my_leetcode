class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
       vector<int>vp;
        for(auto i:nums){
            int v=i/2;
            while(v<i){
                if((v|(v+1))==i)break;
                v+=1;
            }
            if(v==i)v=-1;
            vp.push_back(v);
            }
            return vp;
    }
};