class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& grpsize) {
        stack<vector<int>>s;
        int n=types.size();
        for(int i=0;i<n;i++){
            int t=types[i];
            int c=colors[i];
            if(s.size() && s.top()[0]==t && s.top()[1]==c){
                s.top()[2]++;
            }
            else{
                s.push({t,c,1});
            }
            if(s.size() && s.top()[2]==grpsize[t]){
                s.pop();
            }
        }
        return s.empty();
    }
};