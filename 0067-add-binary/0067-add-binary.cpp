class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> vp1(a.size());
        vector<int> vp2(b.size());
        for(int i=0;i<a.size();i++){
            if(a[i]=='1')vp1[i]=1;
            else vp1[i]=0;;
        }
         for(int i=0;i<b.size();i++){
            if(b[i]=='1')vp2[i]=1;
            else vp2[i]=0;
        }
        int n1=vp1.size();
        int n2=vp2.size();
        int i=n1-1;
        int j=n2-1;
        int carry=0;
       // int sum=0;
       int x=max(n1,n2);
vector<int> ans(x+1);
int k=x;
        while(i>=0 || j>=0|| carry){
            int sum=0;
            if(i>=0)
            sum+=vp1[i];
            if(j>=0){
                sum+=vp2[j];
            }
            sum+=carry;
          if(sum==3){ans[k]=1;
          carry=1;
          }
          else if(sum==2){
              ans[k]=0;
              carry=1;
          }
          else{
              ans[k]=sum;
              carry=0;
          }
          k--;
          i--;
          j--;


        }

        string res="";
        
        for(int i=0;i<ans.size();i++){
            if(i==0 && ans[i]==0)continue;
            res+=to_string(ans[i]);
        }
        return res;

    }
};
 
