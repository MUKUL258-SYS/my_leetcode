class Solution {
public:
    string rankTeams(vector<string>& votes) {
       ///just create mapping for all alphabets like for w-14,x-12,y-23,z-34 and simply sort them 
       vector<vector<int>>vp(26);
       if(votes.size()==1)return votes[0];
       int n=votes.size();
       for(int i=0;i<n;i++){
        for(int j=0;j<votes[i].size();j++){
            int idx=votes[i][j]-'A';
           // vp[idx]+=to_string(j);
           vp[idx].push_back(j);
        }
       }
       for(auto &i:vp){
        sort(i.begin(),i.end());
       }
       /*for(auto i:vp){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
       }*/
       int k=0;
         //vector<string>v;
        vector<pair<string,string>>res;
        char ch='A';
       for(auto i:vp){
          if(i.size()==0){
            ch++;
            continue;
          }
          string str="";
        for(auto j:i){
              str+=(j+'0');
        }
        res.push_back({str,string(1,ch)});
       ch++;
        
       }
      
      /* vector<pair<string,string>>res;
       for(int i=0;i<26;i++){
            if(vp[i]=="")continue;
            res.push_back({vp[i],string(1,i+'A')});
       }
       */
       sort(res.begin(),res.end());
       string ans="";
       /*for(auto i:res){
        cout<<i.first<<" "<<i.second<<endl;
       }
       */
       
       
       for(auto i:res){
        ans+=(i.second);
       }
       return ans;
       
    

    }
};