class Solution {
    
public:
    vector<int> sortByBits(vector<int>& arr) {
      /*  sort(arr.begin(),arr.end(),[&](const int & a,const int &b){
            int x=__builtin_popcount(a);
            int y=__builtin_popcount(b);
            if(x<y)return a<b;
            else return a<b;
        });
        */
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