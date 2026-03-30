class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        if(s==t)return 0;
        int type1=0;
        int type2=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==t[i])continue;
            if(s[i]=='1'&&t[i]=='0')type1++;
            else type2++;
        }
        cout<<type1<<" "<<type2<<endl;
        int mini=min(type1,type2);
        int maxi=max(type1,type2);
        long long cost=0;
        cost+=min(mini*1ll*swapCost,mini*2ll*flipCost);
        maxi-=mini;
        int half=maxi/2;
        cost+=min(1ll*half*(swapCost+crossCost),2ll*half*flipCost);
        if(maxi%2)cost+=(1ll*flipCost);
        return cost;
    }
};