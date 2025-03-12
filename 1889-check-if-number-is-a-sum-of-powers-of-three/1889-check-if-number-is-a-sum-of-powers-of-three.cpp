class Solution {
public:
long long target;
bool dfs(long long sum,long long power){
   if(sum==target)return true;
   if(sum>target||power>target)return false;
   //if(sum==target)return true;
   return dfs(sum,power*3)||dfs(sum+power,power*3);
}
    bool checkPowersOfThree(int n) {
        target=n;
           return dfs(0,1);
    }
};