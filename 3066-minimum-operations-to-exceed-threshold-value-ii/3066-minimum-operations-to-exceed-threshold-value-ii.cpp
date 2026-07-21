class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto i:nums)pq.push(i);
        int cnt=0;
        while(pq.size()>=2){
            long long a=pq.top();
            pq.pop();
            if(a>=k)break;
            long long b=pq.top();
            pq.pop();
            cnt++;
            long long value=min(a,b)*2+max(a,b);
            pq.push(value);


        }
        return cnt;
    }
};