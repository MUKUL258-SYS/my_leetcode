class Solution {
public:
    long long numberOfWeeks(vector<int>& mil) {
        
        long long sum=0;
        long long mx=0;
        for(auto i:mil){
             mx=max(mx,1ll*i);
             sum+=i;
        }
        long long diff=sum-mx;
        if(mx>diff){
            return 2*diff+1;
        }
        else if(mx==diff){
            return 2*diff;
        }
        return sum;

    }
};