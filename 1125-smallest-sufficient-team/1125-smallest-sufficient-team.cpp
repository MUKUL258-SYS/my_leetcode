/*class Solution {
public:
unordered_map<string,int>mp;
vector<vector<vector<int>>>dp;
int m;
  vector<int>v;
  int n;
  vector<vector<string>>nums;
vector<int>dfs(int idx,int mask){
    // n=mp.size();
    if(mask== (1<<n)-1){
        return {};
    }
    if(idx==m)return vector<int>(m+1,-1);
   if(!dp[idx][mask].empty())return dp[idx][mask];
    vector<int>op1=dfs(idx+1,mask);
    vector<int>op2;
    int newmask=mask|v[idx];
    if(newmask!=mask){
        op2=dfs(idx+1,newmask);
        op2.push_back(idx);
    }
    else op2=vector<int>(m+1,-1);
    if(op2.size()<op1.size())dp[idx][mask]=op2;
    else dp[idx][mask]=op1;
    return dp[idx][mask];
}
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        nums=people;
        int k=0;
        m=nums.size();
       n=req_skills.size();
        for(auto i:req_skills){
            mp[i]=k++;
        }
       // vector<int>v;
        for(auto i:people){
            int mask=0;
            for(auto j:i)mask=mask|(1<<mp[j]);
            v.push_back(mask);
        }
       // dp.resize(m,vector<int>(1<<n));
       dp.assign(m, vector<vector<int>>(1 << n));
        return dfs(0,0);
    }
};
*/
class Solution {
public:
    int n;
    unordered_map<string,int>mp;
    vector<int>res;
    int sz=INT_MAX;
    unordered_map<string,int>dp;
    void solve(int id,int mask,vector<int>&sp,vector<int>&z){
        if(mask== (1<<n)-1){
            if(sz>z.size()){
                res=z;
                sz=z.size();
            }
            return;
        }
        if(mask & (1<<id)){
            solve(id+1,mask,sp,z);
            return;
        }
        for(int i=0;i<sp.size();i++){
            if(sp[i]&(1<<id)){
                int new_mask=(mask|sp[i]);
                z.push_back(i);
                solve(id+1,new_mask,sp,z);
                z.pop_back();
            }
        }
        return;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        this->n=req_skills.size();
        int i=0;
        for(auto it:req_skills){
            mp[it]=i;
            i++;
        }
        vector<int>sp;
        for(auto it:people){
            int temp=0;
            for(auto s:it){
                temp+=(1<<mp[s]);
            }
            sp.push_back(temp);
        }
        vector<int>z;
        solve(0,0,sp,z);
        return res;
    }
};