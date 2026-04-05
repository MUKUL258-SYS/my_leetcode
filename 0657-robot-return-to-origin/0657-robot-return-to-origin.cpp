class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,pair<int,int>>mp;
        mp['L']={0,-1};
        mp['R']={0,1};
        mp['U']={1,0};
        mp['D']={-1,0};

        pair<int,int>p={0,0};
        int n=moves.size();
        for(int i=0;i<n;i++){
           p.first+=mp[moves[i]].first;
           p.second+=mp[moves[i]].second;
        }
        if(p.first==0&&p.second==0)return true;
        return false;

    }
};