class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
         vector<pair<int,int>>vp;
         int n=score.size();
         for(int i=0;i<n;i++){
            vp.push_back({score[i],i});
         }
         sort(vp.begin(),vp.end());
         reverse(vp.begin(),vp.end());
        vector<string>res(n);
        int cnt=0;
        for(auto &[val,idx]:vp){
            if(cnt<3){
                if(cnt==0)res[idx]="Gold Medal";
                else if(cnt==1)res[idx]="Silver Medal";
                else res[idx]="Bronze Medal";
            }
            else{
               res[idx]=to_string(cnt+1);
            }
            cnt++;
        }
        return res;
    }
};