class Solution {
public:
int d1,d2,r1,r2; 
bool helper(long long time){
    long long deliveries1=time-(time/r1);
    long long deliveries2=time-(time/r2);
    if(deliveries1<d1)return false;
    if(deliveries2<d2)return false;

    long long commond=lcm(r1,r2);

    return d1+d2 <= (time-(time/commond));
}
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long s=0;
        long long e=1e18;
        d1=d[0];
        d2=d[1];
        r1=r[0];
        r2=r[1];
        long long ans=e;
        while(s<=e){
            long long mid=(s+e)/2;
            if(helper(mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};