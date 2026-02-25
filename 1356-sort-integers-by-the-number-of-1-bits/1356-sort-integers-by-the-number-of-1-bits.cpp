class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
         vector<pair<int,int>>v;
        for(auto i:arr){
            int x=__builtin_popcount(i);
            v.push_back({x,i});
        }
        sort(v.begin(),v.end());
        arr.clear();
        for(auto i:v)arr.push_back(i.second);
        return arr;
    }
};