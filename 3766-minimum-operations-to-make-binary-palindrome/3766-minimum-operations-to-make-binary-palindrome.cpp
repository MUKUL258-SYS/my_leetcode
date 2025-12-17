class Solution {
public:
bool ispal(int n){
    string str="";
    while(n>0){
        str+=(n%2+'0');
        n/=2;
    }
//cout<<str<<endl;
    int i=0;
    int j=str.size()-1;
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    } 
    cout<<str<<endl;
    return true;
}
    vector<int> minOperations(vector<int>& nums) {
        vector<int>v;
        for(int i=1;i<=5000;i++){
            if(ispal(i)){
                v.push_back(i);
            }
        }
        vector<int>ans;
        for(auto i:nums){
            auto itr1=lower_bound(v.begin(),v.end(),i);
            auto itr2=upper_bound(v.begin(),v.end(),i);
            int mini=INT_MAX;
            if(itr1!=v.end()&&(*itr1==i)){
               ans.push_back(0);
               continue;
            }
            if(itr1!=v.begin()){
                mini=min(mini,(i-*(itr1-1)));
            }
            if(itr2!=v.end()){
                mini=min(mini,(*itr2-i));
            }
            ans.push_back(mini);
            
        }
        return ans;

    }
};