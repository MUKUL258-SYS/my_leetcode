class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>v;
        stringstream ss(s);
        string temp;
        //vector<string>v;
        int maxi=0;
        while(getline(ss,temp,' ')){
         v.push_back(temp);
         maxi=max(maxi,(int)temp.size());
        }
        vector<string>vp;
       for(auto str:v){
        while(str.size()<maxi){
            str+=" ";
        }
        vp.push_back(str);
       }

      vector<string>res;
      for(int i=0;i<maxi;i++){
        string s1;
        for(auto j:vp){
            s1+=j[i];
        }
        res.push_back(s1);
      }

      for(auto &i:res){
          while(i.back()==32)i.pop_back();
      }
      return res;


    }
};