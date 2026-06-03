class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>pre,post;
        int cost=1;
        pre.push_back(0);
        pre.push_back(cost);
        for(int i=1;i+1<n;i++){
           int v0=abs(nums[i]-nums[i-1]);
           int v1=abs(nums[i+1]-nums[i]);
           if(v0<=v1){
            cost+=v1;
           }
           else cost++;
           pre.push_back(cost);
        }
       // pre.push_back(cost);
       post.push_back(0);
        post.push_back(1);
        cost=1;
        for(int i=n-2;i>=1;i--){
        int v0=abs(nums[i]-nums[i-1]);
           int v1=abs(nums[i]-nums[i+1]);
         //  cout<<v0<<v1<<endl;
           if(v0>v1){
            cost+=v0;
           }
           else cost++;

           post.push_back(cost);
        }
         //post.push_back(cost);
         reverse(post.begin(),post.end());
         for(auto i:pre)cout<<i<<" ";
         cout<<endl;
         for(auto i:post)cout<<i<<" ";
         cout<<endl;
         
        vector<int>v;
        for(auto vp:queries){
            int l=vp[0];
            int r=vp[1];
           if(l==r){
            v.push_back(0);
            continue;
           }

           //int v=l-1>=0
           if(l<r){
           // v.push_back((l-1>=0?pre[r]-pre[l-1]:pre[r]));
           v.push_back(pre[r]-pre[l]);
           }
           else{
      // v.push_back((l-1>=0?post[r]-post[l-1]:post[r]));
      v.push_back(post[r]-post[l]);
           }
        }
        return v;
    }
};