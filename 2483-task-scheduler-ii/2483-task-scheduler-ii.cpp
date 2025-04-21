class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long>mp;
        long long days=0;
        for(int i=0;i<tasks.size();i++){
           if(mp[tasks[i]]>0){
            if(days-mp[tasks[i]]>space){
                days++;
                mp[tasks[i]]=days;

            }
            else{
                days=mp[tasks[i]]+space+1LL;
                mp[tasks[i]]=days;
            }
           }
           else{
            days++;
            mp[tasks[i]]=days;
           }
        }
        return days;
    }
};