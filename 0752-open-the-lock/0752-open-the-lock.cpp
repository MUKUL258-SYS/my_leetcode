class Solution {
public:
    int openLock(vector<string>&d, string target) {
        unordered_set<string>s(d.begin(),d.end());
        if(s.count(target)||s.count("0000"))return -1;
        queue<pair<string,int>>q;
        q.push({"0000",0});
        unordered_set<string>vis;
        vis.insert("0000");
        while(q.size()){
            auto f=q.front();
            string str=f.first;
            int steps=f.second;
            q.pop();
            if(str==target)return steps;
            for(int k=0;k<4;k++){
                for(int delta:{-1,1}){
                    int digit=(str[k]-'0'+delta+10)%10;
                    string nstr=str;
                    nstr[k]=digit+'0';
                    if(!vis.count(nstr)&&!s.count(nstr)){
                        vis.insert(nstr);
                        q.push({nstr,steps+1});
                    }
                }
            }
        }
        return -1;
    }
};