class Solution {
public:
void dfs(int label,int row,vector<int>&ans){
    if(label==1){
        ans.push_back(1);
        return ;
    }
    ans.push_back(label);
    int parent=label/2;
    int e_row=pow(2,row)-1;
    int s_row=pow(2,row-1);
    int diff=e_row-parent;
    int nparent=s_row+diff;
    dfs(nparent,row-1,ans);
}
    vector<int> pathInZigZagTree(int label) {
       vector<int>ans;
       dfs(label,log2(label),ans);
       reverse(ans.begin(),ans.end());
       return ans; 
    }
};