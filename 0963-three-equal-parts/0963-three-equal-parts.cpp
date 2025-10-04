class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n=arr.size(),ones=count(arr.begin(),arr.end(),1);
        if(ones%3)return {-1,-1};
        if(ones==0)return {0,n-1};
        int f=-1,s=-1,t=-1;
        ones=ones/3;
        int onecount=0;
        int l=0;
        for(auto i:arr){
            if(i==1)onecount++;
            if(onecount==1&&f==-1)f=l;
            else if(onecount==ones+1&&s==-1)s=l;
            else if(onecount==2*ones+1&&t==-1)t=l;
            l++;
        }
        int i,j,k;
        for(i=f,j=s,k=t;k<n;i++,j++,k++){
            if(!(arr[i]==arr[j]&&arr[j]==arr[k]))return {-1,-1};
        }
        return {i-1,j};


    }
};