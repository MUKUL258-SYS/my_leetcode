class Solution {
public:
    long long calculateScore(vector<string>& inst, vector<int>& values) {
        int n=values.size();
        vector<bool>vis(n,false);
        long long score=0;
        for(int i=0;i<n;){
            vis[i]=true;
            if(inst[i]=="jump"){
                i+=values[i];
            }
            else{
                score+=values[i];
                i++;
            }
            if(i<0 || i>=n || vis[i])break;
            
        }
        return score;
    }
};