class Solution {
public:
int helper(int i,vector<int>v){
    int ans=0;
    int n=v.size();
    for(;i<n;i+=2){
        if(i-1>=0&&v[i-1]<=v[i]){
            ans+=(v[i]-v[i-1]+1);
            v[i]=v[i-1]-1;
        }
        if(i+1<n&&v[i+1]<=v[i]){
            ans+=(v[i]-v[i+1]+1);
            v[i]=v[i+1]-1;
        }
    }
    return ans;
}
    int movesToMakeZigzag(vector<int>& nums) {
        return min(helper(0,nums),helper(1,nums));
    }
};