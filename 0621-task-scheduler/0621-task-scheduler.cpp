class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        unordered_map<char,int>freq;
        for(auto i:tasks)freq[i]++;
        int maxi=0;
        for(auto i:freq)maxi=max(maxi,i.second);
           
        int cnt=0;
        for(auto i:freq)if(i.second==maxi)cnt++;
        
      int ans=(maxi-1)*(n+1)+cnt;
      return std::max(m,ans);

    }
};