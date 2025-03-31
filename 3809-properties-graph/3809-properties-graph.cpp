class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int x){
    if(parent[x]==-1)return x;
    return parent[x]=find(parent[x]);
}
void union_set(int x,int y){
    int rx=find(x);
    int ry=find(y);
    if(rx==ry)return ;
    if(rx>ry){
        parent[ry]=rx;
        rank[rx]+=rank[ry];
    }
    else{
        parent[rx]=ry;
        rank[ry]+=rank[rx];
    }

}
 bool  helper(vector<int>&v1,vector<int>&v2,int k){
    vector<int>vp1(105);
    vector<int>vp2(105);
    for(auto i:v1)vp1[i]++;
    for(auto i:v2)vp2[i]++;
    int cnt=0;
    for(int i=1;i<=100;i++){
        if(vp1[i]>=1&&vp2[i]>=1)cnt++;
    }
    return cnt>=k;
 }
    int numberOfComponents(vector<vector<int>>& p, int k) {
        int n=p.size();
        int m=p[0].size();
        parent.resize(n,-1);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(helper(p[i],p[j],k)){
                    union_set(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1)ans++;
        }
        return ans;
    }
};