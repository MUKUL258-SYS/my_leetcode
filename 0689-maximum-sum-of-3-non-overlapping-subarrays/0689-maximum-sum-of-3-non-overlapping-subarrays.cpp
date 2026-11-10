class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        //int maxi1=0,maxi2=nums[k],maxi3=nums[2*k];
       // int sum1=maxi1,sum2=maxi2,sum3=maxi3;
       int sum1=0,sum2=0,sum3=0;
       int maxi1=0,maxi2=0,maxi3=0;
       for(int i=0;i<k;i++)sum1+=nums[i],sum2+=nums[i+k],sum3+=nums[i+2*k];
       maxi1=sum1;
       maxi2=sum2+sum1;
       maxi3=sum3+sum2+sum1;
       int u=0;
       vector<int>v={0,k};
       vector<int>x={0,k,2*k};
        for(int i=1;(i+(3*k))<=n;i++){
            sum1=sum1-nums[i-1]+nums[i+k-1];
            sum2=sum2-nums[i+k-1]+nums[i+(2*k)-1];
            sum3=sum3-nums[i+(2*k)-1]+nums[i+(3*k)-1];
            if(sum1>maxi1){
                maxi1=sum1;
                u=i;
            }
            if(maxi1+sum2>maxi2){
                maxi2=sum2+maxi1;
                v={u,i+k};
            }
            if(maxi2+sum3>maxi3){
                maxi3=sum3+maxi2;
                x={v[0],v[1],i+2*k};
            }
        }
        return x;

    }
};