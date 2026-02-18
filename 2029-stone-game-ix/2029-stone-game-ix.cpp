class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int>v(3,0);
        for(auto i:stones){
            v[i%3]++;
        }
        int cnt0=v[0];
        if(cnt0%2==0)return (v[1]>0&&v[2]>0);
        int v1=v[1];
        int v2=v[2];
        return abs(v1-v2)>2;
    }
};