class Solution {
public:
int x;
bool helper(long long sum){
    //cout<<sum<<endl;
    int ld=sum%10;
    while(sum>9){
        sum=sum/10;
    }
    return (sum==x && ld==x);


}
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        int cnt=0;
        this->x=x;
        for(int i=0;i<n;i++){
            long long sum=0;
          //if(helper(sum))cnt++;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(helper(sum))cnt++;
                //else break;
                //sum+=nums[j];
            }
        }
        return cnt;
    }
};