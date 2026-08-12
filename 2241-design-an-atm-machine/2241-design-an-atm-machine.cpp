class ATM {
public:
vector<int>nums;
    ATM() {
        nums.resize(5,0);
    }
    
    void deposit(vector<int> b) {
        for(int i=0;i<=4;i++){
            nums[i]+=b[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int>ans(5,0);
        vector<int>v={20,50,100,200,500};
        for(int i=4;i>=0;i--){
            ans[i]=min(nums[i],amount/v[i]);
           // nums[i]-=ans[i];
           amount-=(ans[i]*v[i]);
        }
        if(amount==0){
            for(int i=0;i<=4;i++){
                nums[i]-=ans[i];
            }
            return ans;
        }
        return {-1};

    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */