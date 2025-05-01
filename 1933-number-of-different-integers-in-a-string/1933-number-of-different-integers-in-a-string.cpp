class Solution {
public:
   /* int numDifferentIntegers(string word) {
        string temp="";
        set<string>s;
        for(auto i:word){
            if(i>='a'&&i<='z'){
                if(temp.size()>0){
                    reverse(temp.begin(),temp.end());
                    while(temp.size()>0&&temp.back()=='0')temp.pop_back();
                     reverse(temp.begin(),temp.end());
                    // cout<<temp<<endl;
                   if(temp.size()==0)temp+='0';
                   s.insert(temp);

                }
                temp.clear();
            }
            else{
                temp+=i;
            }
        }
                if(temp.size()>0){
                     reverse(temp.begin(),temp.end());
                    while(temp.size()>0&&temp.back()=='0')temp.pop_back();
                     reverse(temp.begin(),temp.end());
                    s.insert(temp);
                    //cout<<temp<<endl;
                    if(temp.size()==0)temp+='0';
                   s.insert(temp);
                }

              for(auto i:s)cout<<i<<endl;
        return s.size();
    }
    */
    int numDifferentIntegers(string word) {
    string temp = "";
    set<string> s;

    for (auto i : word) {
        if (i >= 'a' && i <= 'z') {
            if (!temp.empty()) {
                // Remove leading zeros
                reverse(temp.begin(), temp.end());
                while (!temp.empty() && temp.back() == '0') temp.pop_back();
                reverse(temp.begin(), temp.end());

                if (temp.empty()) temp = "0";
                s.insert(temp);
                temp.clear();
            }
        } else {
            temp += i;
        }
    }

    if (!temp.empty()) {
        reverse(temp.begin(), temp.end());
        while (!temp.empty() && temp.back() == '0') temp.pop_back();
        reverse(temp.begin(), temp.end());

        if (temp.empty()) temp = "0";
        s.insert(temp);
    }

    return s.size();
}

};
