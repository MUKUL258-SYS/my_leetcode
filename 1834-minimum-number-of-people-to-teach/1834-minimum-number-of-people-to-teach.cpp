class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& f) {
        unordered_set<int>s;
        for(auto i:f){
            int f1=i[0]-1;
            int f2=i[1]-1;
            bool f=false;
            for(auto j:l[f1]){
                for(auto k:l[f2]){
                   if(j==k){
                    f=true;
                    break;
                   }
                }
                if(f)break;
            }
            if(!f){
                s.insert(f1);
                s.insert(f2);
            }

        }
        int mini=s.size()+1;
        for(int i=1;i<=n;i++){
           // bool f=false;
            int cnt=0;
            for(auto j:s){
                bool f=false;
                for(auto k:l[j]){
                    if(k==i){
                        f=true;
                        break;
                    }
                }
                if(!f)cnt++;
            }
            mini=min(mini,cnt);
        }
        return mini;
    }
};