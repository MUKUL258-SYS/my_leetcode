class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n=words.size();
        unordered_map<int,int>mp;
        vector<int>sizes;
        for(auto &word:words){
            for(auto &w:word)mp[w-'a']++;
            sizes.push_back(word.size());
        }
        int epairs=0;
        int odd=0;
        for(auto i:mp){
            if((i.second%2)==0)epairs+=(i.second/2);
            else{
                odd++;
                epairs+=(i.second/2);
            }
        }
        sort(sizes.begin(),sizes.end());
        int cnt=0;
        for(auto &size:sizes){
            // epairs-=(size/2);
            if(size%2 == 1){
                 //epairs-=(size/2);
                if(odd>0 && epairs>=(size/2)){
                    odd--;
                    epairs-=(size/2);
                    cnt++;
                }else if(epairs>(size/2)){
                    epairs-=(size/2);
                      epairs--;
                      odd++;
                      cnt++;
                    
                    
                }
                else break;
            }
            else{
                if(epairs >= size/2){
                 epairs-=(size/2);
                 cnt++;
                }
                else break;
            }
        }
        return cnt;

    }
};