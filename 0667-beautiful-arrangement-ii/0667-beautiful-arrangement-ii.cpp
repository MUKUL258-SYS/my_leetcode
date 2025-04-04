class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int left=1;
        int right=n;
        vector<int>ans;
        for(int i=0;i<k;i++){
             if(i%2==0){
                ans.push_back(left);
                left++;
             }
             else{
                ans.push_back(right);
                right--;
             }
        }
        if(k%2==1){while(left<=right)
              ans.push_back(left++);
        }
        else{
            while(right>=left)
            ans.push_back(right--);
        }
        return ans;

    }
};