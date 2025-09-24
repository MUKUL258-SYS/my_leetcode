class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int cnt=0;
        while(pq.size()>=2){
            cnt++;
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            a--;
            if(a>0)pq.push(a);
            b--;
            if(b>0)pq.push(b);
        }
        return cnt;
    }
};