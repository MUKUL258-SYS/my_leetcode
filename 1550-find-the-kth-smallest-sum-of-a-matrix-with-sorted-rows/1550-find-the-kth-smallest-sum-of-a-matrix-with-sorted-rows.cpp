class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<int>pq;
        for(int i=0;i<m;i++)pq.push(mat[0][i]);
        for(int i=1;i<n;i++){
            priority_queue<int>pnew;
            while(!pq.empty()){
              int top=pq.top();
              pq.pop();
              for(int j=0;j<m;j++){
                int s=top+mat[i][j];
                if(pnew.size()<k){
                    pnew.push(s);
                }
                else{
                    if(s<pnew.top()){
                        pnew.pop();
                        pnew.push(s);
                    }
                }
              }
            }
            pq=pnew;
        }
        return pq.top();
    }
};