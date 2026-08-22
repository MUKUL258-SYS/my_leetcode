class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long sum=0;
        if(nums==target)return 0;
        //sort(nums.begin(),nums.end());
        //sort(target.)
        vector<int>e1,e2,o1,o2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                e1.push_back(nums[i]);
            }
            else o1.push_back(nums[i]);

            if(target[i]%2==0){
                e2.push_back(target[i]);
            }
            else o2.push_back(target[i]);
        }
        sort(e1.begin(),e1.end());
        sort(o1.begin(),o1.end());
        sort(e2.begin(),e2.end());
        sort(o2.begin(),o2.end());
         n=e1.size();
        int m=o1.size();
    
        for(int i=0;i<m;i++){
           if(o2[i]>o1[i]){
               sum+=((o2[i]-o1[i])/2);
           }
        }
        for(int i=0;i<n;i++){
            if(e2[i]>e1[i]){
                sum+=((e2[i]-e1[i])/2);
            }
        }
        return sum;


        
    }
};