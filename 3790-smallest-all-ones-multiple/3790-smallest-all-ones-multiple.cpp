class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k==2)return -1;
        int num=1;
unordered_map<int,int>mp;
//mp[num]++;
        while(true){
          //  cout<<num<<endl;

             mp[num]++;
            if(num%k==0){
                //return to_string(num).size();
                return mp.size();
            }
            num=(num*10+1)%k;
           // mp[num]++;
            if(mp[num]>0){
                break;
            }
        }
        return -1;
    }
};