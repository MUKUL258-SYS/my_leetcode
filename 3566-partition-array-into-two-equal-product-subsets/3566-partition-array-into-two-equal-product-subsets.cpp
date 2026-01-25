class Solution {
public:
long long target;
vector<int>nums;
bool dfs(int i,long long p1,long long p2,unordered_map<string,bool>&mp){
    int n=nums.size();
    if(i>=n){
        if(p1==target&&p2==target){
            return true;
        }
        return false;
    }
    string s=to_string(i)+to_string(p1)+to_string(p2);
    if(mp.count(s))return mp[s];
    bool op1=dfs(i+1,1ll*p1*nums[i]>target?target+1:1ll*p1*nums[i],p2,mp);
    bool op2=dfs(i+1,p1,1ll*p2*nums[i]>target?target+1:1ll*p2*nums[i],mp);
    return mp[s]=op1||op2;
}
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        this->nums=nums;
        this->target=target;
        unordered_map<string,bool>mp;
        return dfs(0,1,1,mp);
    }
};