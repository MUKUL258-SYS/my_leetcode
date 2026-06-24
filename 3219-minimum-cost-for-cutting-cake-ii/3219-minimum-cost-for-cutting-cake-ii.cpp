class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        
        long long ans=0;
        int h=1;
        int v=1;
        sort(hc.begin(),hc.end(),greater<int>());
        sort(vc.begin(),vc.end(),greater<int>());
        int i=0;
        int j=0;
        m--;
        n--;
        while(i<m && j<n){
            
            if(hc[i]>=vc[j]){
              //  cout<<hc[i]<<endl;
                ans=ans+(1ll*hc[i]*v);
                h++;
                i++;
            }
            else{
               // cout<<vc[j]<<endl;
                ans=ans+(1ll*vc[j]*h);
                v++;
                j++;
            }
        }

        while(i<m){
            ans=ans+(1ll*hc[i]*v);
            i++;
        }
        while(j<n){
            ans=ans+(1ll*vc[j]*h);
            j++;
        }
        return ans;

    }
};