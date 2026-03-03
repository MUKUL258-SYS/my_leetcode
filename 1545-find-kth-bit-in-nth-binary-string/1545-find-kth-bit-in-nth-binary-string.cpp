class Solution {
public:

    char findKthBit(int n, int k) {
        string str="0";
       for(int i=1;i<n;i++){

             string temp=str+"1";
             reverse(str.begin(),str.end());
             for(auto &i:str){
                if(i=='0')i='1';
                else i='0';
             }
             temp+=str;
           //  cout<<temp<<endl;
             str=temp;
       }        
       cout<<str<<endl;
       return str[k-1];
    }
};