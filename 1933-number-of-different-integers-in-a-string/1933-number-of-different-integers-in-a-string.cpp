class Solution {
public:
    int numDifferentIntegers(string word) {
        string temp="";
        set<string>s;
        for(auto i:word){
            if(i>='a'&&i<='z'){
                if(temp.size()>0){
                    reverse(temp.begin(),temp.end());
                    while(temp.size()>0&&temp.back()=='0')temp.pop_back();
                     reverse(temp.begin(),temp.end());
                    // cout<<temp<<endl;
                   if(temp.size()==0)temp="0";
                   s.insert(temp);
                    temp.clear();
                }
                //temp.clear();
            }
            else{
                temp+=i;
            }
        }
                if(temp.size()>0){
                     reverse(temp.begin(),temp.end());
                    while(temp.size()>0&&temp.back()=='0')temp.pop_back();
                     reverse(temp.begin(),temp.end());
                    if(temp.size()==0)temp="0";
                   s.insert(temp);
                }

              for(auto i:s)cout<<i<<endl;
        return s.size();
    }
    

};
