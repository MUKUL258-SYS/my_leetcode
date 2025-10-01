class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        double left=0.0,right=1.0;
        while(left<right){
            double mid=(left+right)/2;
            double maxFraction=0.0;
            int tsmallf=0,nidx=0,didx=0;
            int j=1;
            for(int i=0;i<n-1;i++){
                while(j<n&&arr[i]>=mid*arr[j])j++;
                tsmallf+=(n-j);
                if(j==n)break;
                double f=static_cast<double>(arr[i])/arr[j];
                if(f>maxFraction){
                    nidx=i;
                    didx=j;
                    maxFraction=f;
                }

            }
                if(tsmallf==k)return {arr[nidx],arr[didx]};
                else if(tsmallf>k)right=mid;
                else left=mid;


            }
        return {};
    }
};