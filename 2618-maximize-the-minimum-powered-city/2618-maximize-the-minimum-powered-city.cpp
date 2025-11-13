class Solution {
public:
bool checker(vector<int>stations,int r,int a,long long mid){
    const int n=stations.size();
    long long power=accumulate(stations.begin(),stations.begin()+r,0LL);
    for(int i=0;i<n;i++){
        if(i+r<n)power+=stations[i+r];
        if(power<mid){
            long  reqpower=mid-power;
            if(reqpower>a)return false;
            stations[min(n-1,i+r)]+=reqpower;
            a-=reqpower;
            power+=reqpower;
        }
        if(i-r>=0)power-=stations[i-r];
    }
    return true;
}
    long long maxPower(vector<int>& stations, int r, int k) {
        long long left=ranges::min(stations);
        long long right=accumulate(stations.begin(),stations.end(),0LL)+k+1;
        while(left<right){
            const long long mid=(left+right)/2;
            if(checker(stations,r,k,mid)){
                left=mid+1;
            }
            else right=mid;
        }
        return left-1;
    }

};