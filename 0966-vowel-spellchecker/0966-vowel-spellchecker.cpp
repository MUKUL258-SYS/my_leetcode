class Solution {
public:
unordered_map<string,int>mp;
vector<string>words;
int n;
bool isVowel(char ch){
    if(ch=='a'||ch=='e'|| ch=='i'|| ch=='o'|| ch=='u')return true;

  return false;
}


    vector<string> spellchecker(vector<string>& words, vector<string>& queries) {
        n=words.size();
        vector<pair<string,int>>v1,v2;
        for(int k=0;k<n;k++){
            string i=words[k];
            string s="";
            string t="";
           for(auto j:i){
            char ch=std::tolower(j);
            s+=ch;
            if(isVowel(ch))t+='@';
            else t+=ch;
           }
           v1.push_back({s,k});
           v2.push_back({t,k});
            mp[i]++;
        }

        vector<string>vp;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        this->words=words;
        for(auto i:queries){
            if(mp[i]>0){
                vp.push_back(i);
                continue;
            }
             string s="";
             string t="";
           for(auto j:i){
            char ch=std::tolower(j);
            s+=ch;
            if(isVowel(ch))t+='@';
            else t+=ch;
           }
           auto itr1 = std::lower_bound(v1.begin(), v1.end(), make_pair(s,INT_MIN));
           if(itr1!= v1.end() && itr1->first == s){
            vp.push_back(words[itr1->second]);
            continue;
           }
           auto itr2= std::lower_bound(v2.begin(),v2.end(),make_pair(t,INT_MIN));
           if(itr2!= v2.end() && itr2->first == t){
            vp.push_back(words[itr2->second]);
            continue;
           }

          
            vp.push_back("");
            
        }
       /* for(int i=0;i<n;i++){
            cout<<words[i]<<" "<<v1[i]<<" "<<v2[i]<<endl;
        }
        */
        return vp;
    }
};