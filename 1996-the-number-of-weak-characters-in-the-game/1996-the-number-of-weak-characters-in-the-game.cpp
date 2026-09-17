class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        //return 0;
        sort(p.begin(),p.end(),[](const vector<int>&a,const vector<int>&b){
                    if(a[0]!=b[0]){
                        return a[0]>b[0];
                    }
                    else return a[1]<b[1];
        });
        int maxi=0;
        int cnt=0;
        for(auto i:p){
            if(i[1]>=maxi){
                maxi=max(maxi,i[1]);
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};