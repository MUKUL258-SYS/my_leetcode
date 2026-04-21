class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n=rolls.size();
        set<int>s;
        int cnt=0;
        for(int i=0;i<n;i++){
          if(s.size()==k){
            cnt++;
            s.clear();
          }
          
            s.insert(rolls[i]);
        }
        if(s.size()==k){
            cnt++;
        //   s.clear();
          }

        return cnt+1;
    }
};