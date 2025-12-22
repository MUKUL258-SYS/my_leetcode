class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_set<string>st;
        bool flag=false;
        for(int i=0;i<n;i++){
            vector<int>next(8,0);
            for(int j=1;j<7;j++){
                next[j]=(cells[j-1]==cells[j+1])?1:0;

            }
            string s;
            for(auto x:next){
                s+=(x+'0');
            }
            if(!st.count(s))st.insert(s);
            else {
                flag=true;
                break;
            }
            cells=next;
        }
        if(flag){
            n=n%st.size();
            for(int i=0;i<n;i++){
                vector<int>next(8,0);
                for(int j=1;j<7;j++){
                    next[j]=(cells[j-1]==cells[j+1])?1:0;
                }
                cells=next;
            }
        }
        return cells;
    }
};