class Solution {
public:
int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.insert(h.begin(),1);
        v.insert(v.begin(),1);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        h.push_back(m);
        v.push_back(n);
        int a=h.size();
        int b=v.size();
        int maxi1=0;
        int maxi2=0;
        unordered_map<int,int>mp1,mp2;
        for(int i=0;i<a;i++){
            for(int j=i+1;j<a;j++){
              mp1[h[j]-h[i]]++;
            }
        }
        for(int i=0;i<b;i++){
            for(int j=i+1;j<b;j++){
            mp2[v[j]-v[i]]++;
            }
        }
        long long maxi=-1;
        for(auto i:mp1){
            if(mp2[i.first]>0){
                int vl=i.first;
               // maxi=max(maxi,(1ll*vl*vl)%mod);
               maxi=max(maxi,1ll*(i.first));
            }
        }
        if(maxi==-1)return -1;
        return (maxi*maxi)%mod;;
    }
};