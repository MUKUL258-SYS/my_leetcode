class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n=num.size();
        string str="";
        for(auto i:num){
            str+=to_string(change[i-'0']);
        }
        cout<<str<<endl;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(num[i]<str[i]){
                 idx=i;
                 break;
            }
        }
        if(idx==-1)return num;
        while(idx<n&&(num[idx]<=str[idx])){
            num[idx]=str[idx];
            idx++;
        }
        return num;
    }
};