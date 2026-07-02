class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int>v;
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        int n=arr1.size();
        int m=arr2.size();
        int l=max(n,m)+2;
        int sum=0;
        int carry=0;
        for(int i=0;i<l;i++){
            int x=i<n?arr1[i]:0;
            int y=i<m?arr2[i]:0;
            sum=x+y+carry;
            int r=sum%(-2);
            carry=sum/(-2);
            if(r<0){
                r+=2;
                carry+=1;
            }
            v.push_back(r);
        }
        while(v.size()>1 && v.back()==0)v.pop_back();
        reverse(v.begin(),v.end());
        return v;
    }

};