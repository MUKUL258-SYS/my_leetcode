class Solution {
public:
int helper(vector<int>&h){
    int n=h.size();
    stack<int>s;
    //int n=h.size();
    int ans=0;
    for(int i=0;i<=n;i++){
        while(s.size()&&(i==n||(h[s.top()]>=h[i]))){
            int idx=s.top();
            s.pop();
            int height=h[idx];
            //int width=i-s.top();
            int width;
            if(s.empty())width=i;
            else{
                width=(i-s.top()-1);
            }
      ans=max(ans,height*width);
        }
        s.push(i);
    }
    return ans;

}
    int maximalRectangle(vector<vector<char>>& mat) {
        vector<int>v;
        int n=mat.size();
        int m=mat[0].size();
        v.resize(m,0);
        int k=0;
        for(int j=0;j<m;j++)v[k++]=mat[0][j]=='1'?1:0;
        int ans=helper(v);
        for(int i=1;i<n;i++){
          //  vector<int>temp;
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1'){
                   v[j]+=1;
                }
                else v[j]=0;
            }
          ans=max(ans,helper(v));
        }
        return ans;
    }
};