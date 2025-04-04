class Solution {
public:
bool helper(vector<int>&ranks,int cars,long long mid){
    for(auto i:ranks){
        long long v=mid/i;
        cars-=floor(sqrt(v));
        if(cars<=0)return true;
    }
    return cars<=0;
}
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        long long e=(long long)ranks[0]*cars*cars;
        long long s=1;
        long long ans=e;
        while(s<=e){
            long long mid=(s+e)/2;
            if(helper(ranks,cars,mid)){
             ans=min(ans,mid);
             e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};