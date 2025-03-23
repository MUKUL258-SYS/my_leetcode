class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n==1)return{1};
        vector<int>odd=beautifulArray((n+1)/2);
        vector<int>even=beautifulArray(n/2);
        vector<int>ans;
        vector<int>temp;
        for(auto i:odd){
            temp.push_back(2*i-1);
        }
        for(auto i:even){
            temp.push_back(2*i);
        }
        return temp;
    }
};