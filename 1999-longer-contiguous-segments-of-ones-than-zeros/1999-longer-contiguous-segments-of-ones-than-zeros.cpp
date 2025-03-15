class Solution {
public:
int helper(string s,char ch){
    //int len=0;
    int n=s.size();
    int maxi=0;
    int j=-1;
    int i;
    for(i=0;i<n;){
      if(s[i]==ch){
        i++;
      }
      else{
        maxi=max(maxi,i-j);
        j=i;
        i++;
      }

    }
      maxi=max(maxi,i-j);
    return maxi;
}
    bool checkZeroOnes(string s) {
      int a=helper(s,'0');
      int b=helper(s,'1');
     // cout<<a<<endl;
      return b>a;  
    }
};