class Solution {
public:
int helper(int n){
   int sum=0;
    while(n>0){
   sum+=(n%10);
   n/=10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end(),[&](const int &v1,const int &v2){
            if(helper(v1)==helper(v2)){
                return v1<v2;
            }
            return helper(v1)<helper(v2);
        });
        /*for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        */
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==v[i])continue;
           int correct_index=mp[v[i]];
           mp[nums[i]]=correct_index;
           swap(nums[i],nums[correct_index]);
            cnt++;
            i--;
        }
        return cnt;
    }
};