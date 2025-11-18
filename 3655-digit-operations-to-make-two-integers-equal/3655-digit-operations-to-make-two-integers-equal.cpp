class Solution {
public:
vector<int>isPrimes;
 void helper(){
    isPrimes.resize(1e5+1,1);
    isPrimes[0]=isPrimes[1]=0;
    for(int i=2;i<=1e5;i++){
        if(isPrimes[i]){
        for(int j=i*2;j<=1e5;j+=i){
            isPrimes[j]=0;
        }
    }
    }
}
    int minOperations(int n, int m) {
        helper();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        if(isPrimes[n]||isPrimes[m])return -1;
        pq.push({n,n});
        unordered_set<int>vis;
        while(!pq.empty()){
              auto [steps,curr]=pq.top();
              pq.pop();
              if(vis.count(curr))continue;
              vis.insert(curr);
              if(curr==m)return steps;
              string s=to_string(curr);
              for(int i=0;i<s.size();i++){
                char ch=s[i];
                if(ch<'9'){
                    s[i]++;
                    int next=stoi(s);
                    if(!vis.count(next)&&!isPrimes[next])
                    pq.push({steps+next,next});
                     s[i]=ch;
                }
               // s[i]=ch;
                if(s[i]>'0'&&!(i==0&&s[i]=='1')){
                    s[i]--;
                    int next=stoi(s);
                    if(!vis.count(next)&&!isPrimes[next])
                    pq.push({steps+next,next});
                     s[i]=ch;
                }
               // s[i]=ch;
              }
        }
        return -1;
    }
};