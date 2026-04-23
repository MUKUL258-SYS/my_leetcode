class Solution {
public:
vector<long long>res;
void helper(vector<int>&vp){
    int n=vp.size();
    long long sum=0;
    vector<long long>post,pre;
    for(int i=n-1;i>=0;i--){
        sum+=vp[i];
        post.push_back(sum);
    }
    sum=0;
    for(int i=0;i<n;i++){
        sum+=vp[i];
       pre.push_back(sum);
    }
    reverse(post.begin(),post.end());

//for(auto i:post)cout<<i<<" ";
//cout<<endl;
//for(auto i:pre)cout<<i<<" ";
//cout<<endl;
    for(int i=0;i<n;i++){
         long long  value1=(1ll*i)*vp[i] - (i-1>=0?pre[i-1]:0);
         long long value2=(i+1<n?post[i+1]:0) - (1ll*n-i-1)*vp[i];
         res[vp[i]]=value1+value2;
       
    }
}
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        res.resize(n,0);
        for(auto i:mp){
            helper(i.second);
        }
        return res;

    }
};