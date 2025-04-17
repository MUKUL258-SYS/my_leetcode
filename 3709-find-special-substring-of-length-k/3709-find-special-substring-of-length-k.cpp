class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n=s.size();
        //if(k==1)return true;
        for(int i=0;i+k<=n;i++){
            string str=s.substr(i,k);
            set<char>st;
            for(auto j:str)st.insert(j);
            cout<<st.size()<<endl;
            bool f=false;
            if(st.size()==1){
                f=true;
                cout<<"yes"<<endl;
                if(i-1>=0&&s[i]==s[i-1]){
                     cout<<"yes1"<<endl;
                   f=false;
                }
                if(i+k<n&&s[i]==s[i+k]){
                    cout<<"yes2"<<endl;
                  f=false;
                }

            }
            if(f)return true;
            

        }
        return false;
    }
};