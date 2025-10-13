class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<pair<string,string>>v;
        for(auto word:words){
            string s=word;
            sort(word.begin(),word.end());
            v.push_back({word,s});
        }
        for(auto j:v){
            cout<<j.first<<" "<<j.second<<endl;
        }
        int n=words.size();
        for(int i=0;i<n;i++){
            if(v[i].first=="")continue;
            string s=v[i].first;
            for(int j=i+1;j<n;j++){
                if(v[j].first!=s){
                  break;
                }
                v[j].first="";
            }
        }
      /*  for(auto i:v){
            cout<<i.first<<" "<<i.second<<endl;
        }

        */
        vector<string>res;
        for(auto i:v){
            if(i.first!="")res.push_back(i.second);
        }
        return res;


    }
};