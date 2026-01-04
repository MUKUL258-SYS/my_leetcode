class Solution {
public:
int sumFourDivisors(vector<int>& nums) {
        long long sum=0;
        for(auto i:nums){
            int cnt=0;
            int val;
            int d=sqrt(i);
            if((d*d)==i)continue;
            for(int j=2;(j*j)<i;j++){
                
               if((i%j)==0){
                   cnt+=1;
                   val=j;
               }
            }
            if(cnt==1){
                sum+=(i+1);
                sum+=val;
                sum+=(i/val);
            }
        }
        return sum;
    }
};