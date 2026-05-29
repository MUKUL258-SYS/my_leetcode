class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long>v;
        unordered_map<long long,int>mp;
        if(finalSum%2)return v;
        long long curr_sum=0;
        long long rem=-1;
        for(int i=2;;i+=2){
             rem=finalSum-curr_sum;
             if(rem<=0)break;
            if(mp[rem]>0){
             // v.push_back(v.back()+rem);
              break;
            }
            mp[i]++;
            curr_sum+=i;
            v.push_back(i);
        }
       v.back()+=rem;
       cout<<v.back()<<endl;
       long long sum=0;
       for(auto i:v){
        sum+=i;
       }
       cout<<sum<<endl;
        return v;
    }
};