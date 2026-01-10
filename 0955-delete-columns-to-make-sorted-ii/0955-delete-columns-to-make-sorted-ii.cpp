class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        bitset<100>isorted,remove;
        int n=strs.size();
        int m=strs[0].size();
        for(int j=0;j<m;j++){
            for(int i=0;i<n-1;i++){
                if(isorted[i]==0&(strs[i][j]>strs[i+1][j])){
                    remove[j]=1;
                    break;
                }
            }
            if(remove[j])continue;
            for(int i=0;i<n-1;i++){
                if((strs[i][j]<strs[i+1][j])|isorted[i]){
                    isorted[i]=1;
                }
            }
        }
        return remove.count();

    }
};