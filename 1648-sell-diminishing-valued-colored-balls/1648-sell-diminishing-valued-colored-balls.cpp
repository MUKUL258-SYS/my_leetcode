class Solution {
public:
int mod;
    int maxProfit(vector<int>& inv, int orders) {
        mod=1e9+7;
        long long res=0,prev=0,curr,color=1;
        sort(inv.begin(),inv.end());
        int n=inv.size();
        for(int i=n-1;i>=0 && orders>0;i--,color++){
            curr=inv[i];
            prev=i>0?inv[i-1]:0;
            long long rounds=min(orders/color,curr-prev);
            orders-=(rounds*color);
            res=(res+(curr*(curr+1)-(curr-rounds)*(curr-rounds+1))/2*color)%mod;
            if(curr-prev>rounds){
                res=(res+(curr-rounds)*orders)%mod;
                break;
            }
        }
        return res;

    }
};