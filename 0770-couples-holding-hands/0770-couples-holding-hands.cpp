class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
     unordered_map<int,int>mp;
     for(int i=0;i<row.size();i++){
        mp[row[i]]=i;
     }
int cnt=0;
int n=row.size();
     for(int i=0;i<n;i+=2){
        int val=row[i];
        int c_val;
        if(row[i]%2){
          c_val=row[i]-1;
        }
        else{
          c_val=row[i]+1;
        }
        int idx=mp[c_val];
        int diff=abs(idx-i);
        if(diff==1)continue;
  if(i+1<n){
    mp[row[i+1]]=idx;
    mp[row[idx]]=i+1;
    swap(row[i+1],row[idx]);
     
  }
  cnt++;
     }
     return cnt;  
    }
};