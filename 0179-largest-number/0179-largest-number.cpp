bool cmp(string a,string b){
    return a+b>b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto i:nums){
            v.push_back(to_string(i));
        }
        sort(v.begin(),v.end(),cmp);
        string res="";
        for(auto i:v){
            res+=i;
        }
        return res[0]=='0'?"0":res;
    }
};