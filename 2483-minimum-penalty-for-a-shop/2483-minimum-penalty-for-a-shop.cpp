class Solution {
public:
    int bestClosingTime(string c) {
        int n=c.size();
        vector<int>pre(n,0),post(n,0);
        for(int i=0;i<n;i++){
            if(c[i]=='N')pre[i]++;
            if(i>0)pre[i]+=pre[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(c[i]=='Y')post[i]++;
            if(i+1<n)post[i]+=post[i+1];
        }
       /* for(int i=0;i<n;i++){
            cout<<pre[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<post[i]<<" ";
        }
        */
        int mini=post[0];
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=pre[i]+(i+1<n?post[i+1]:0);
           // cnt--;
            cout<<cnt<<endl;
              if(cnt<mini){
                 ans=i+1;
                 mini=cnt;
              }
        }
        return ans;
    }
};