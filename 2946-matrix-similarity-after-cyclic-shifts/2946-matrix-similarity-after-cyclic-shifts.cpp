class Solution {
public:
void right_shift(vector<int>&v){
     int n=v.size();
    int value=v[n-1];
    for(int i=n-2;i>=0;i--){
        v[i+1]=v[i];
    }
    v[0]=value;
}
void left_shift(vector<int>&v){
    int n=v.size();
    int value=v[0];
    /*for(int i=n-1;i>=1;i--){
        v[i-1]=v[i];
    }*/
    for(int i=1;i<n;i++){
        v[i-1]=v[i];
    }
    v[n-1]=value;
}
void helper(vector<vector<int>>&mat){
     int n=mat.size();
     int m=mat[0].size();
     for(int i=0;i<n;i++){
            if(i%2){
                right_shift(mat[i]);
            }
            else{
                left_shift(mat[i]);
            }
        }
      
}
    bool areSimilar(vector<vector<int>>& mat, int k) {
       int n=mat.size();
       int m=mat[0].size();
       vector<vector<int>>t=mat;
       while(k--){
        helper(mat);
       } 
      
       return t==mat;
    }
};