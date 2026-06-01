class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        if(n<=2){
            int sum=0;
            for(auto i:cost)sum+=i;
            return sum;
        }
        int i=n-1;
        int sum=0;
        for(;i>=2;i-=3){
            sum+=(cost[i]);
            sum+=(cost[i-1]);
        }
        int cnt=0;
        while(i>=0&&cnt<=2){
            sum+=(cost[i--]);
            cnt++;
        }
        return sum;
    }
};