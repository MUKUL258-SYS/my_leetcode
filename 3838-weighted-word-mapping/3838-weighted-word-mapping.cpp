class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& w) {
        string res;
        for(auto word:words){
           int sum=0;
           for(auto i:word){
            sum+=w[i-'a'];
           }
           sum=sum%26;
           res.push_back('z'-sum);
        }
        return res;
    }
};