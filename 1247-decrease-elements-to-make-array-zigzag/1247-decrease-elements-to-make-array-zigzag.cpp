class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int val1=0,val2=0;
        int n=nums.size();
        vector<int>temp1=nums;
        vector<int>temp2=nums;
        for(int i=1;i<n;i++){
            if(i%2==1){
                if((i+1<n&&temp1[i]<temp1[i-1]&&temp1[i]<temp1[i+1]))continue;
                if((i+1>=n&&temp1[i]<temp1[i-1]))continue;
                int v=temp1[i];
                if(i+1<n)
                temp1[i]=min(temp1[i-1],temp1[i+1])-1;
                else
                temp1[i]=temp1[i-1]-1;
                 val1+=(v-temp1[i]);
                 i++;
            }
            cout<<val1<<endl;
        }
        cout<<endl;
        cout<<endl;
        if(temp2.size()>=2&&temp2[0]>=temp2[1]){
            int v=temp2[0];
            temp2[0]=temp2[1]-1;
            val2+=v-temp2[0];
            cout<<val2<<endl;
        }
        for(int i=2;i<n;i++){
            if(i%2==0){
                if((i+1<n&&temp2[i]<temp2[i-1]&&temp2[i]<temp2[i+1]))continue;
                if((i+1>=n&&temp2[i]<temp2[i-1]))continue;
                int v=temp2[i];
                if(i+1<n)
                temp2[i]=min(temp2[i-1],temp2[i+1])-1;
                else
                temp2[i]=temp2[i-1]-1;
                 val2+=(v-temp2[i]);
                 i++;
            }
            cout<<val2<<endl;
        }
        return min(val1,val2);
    }
};