class Solution {
public:
string helper(int n){
    string ans="";
    stack<pair<char,int>>s;
    s.push({'a',n});
    while(true && s.size()){
       auto p=s.top();
       char ch=p.first;
       int f=p.second;
       if(f==1 || ch=='z')break;
       s.pop();
       if(f%2)s.push({ch,1});
       s.push({ch+1,f/2});
       //if(f%2)s.push({ch,1});
    }

    while(s.size()){
        auto t=s.top();
        s.pop();
        char c=t.first;
        int freq=t.second;
        while(freq--)ans+=c;
    }
    return ans;
}
    vector<string> largestString(vector<int>& nums) {
        vector<string>res;
        for(auto i:nums){
            res.push_back(helper(i));
        }
        return res;
    }
};