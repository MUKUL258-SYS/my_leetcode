class Solution {
public:
int n,m,l;
string getmin(string s,string t){
    if(s.size()!=t.size()){
        if(s.size()<t.size())return s;
        else return t;
    }
    return min(s,t);

}
string add(string &s,string &t){
  // if(s.find(t)!=string::npos)return s;
   if(t.find(s)!=string::npos)return t;
   if(s.find(t)!=string::npos)return s;
   for(int i=0;i<s.size();i++){
    string t1=s.substr(i);
    string t2=t.substr(0,t1.size());
    if(t1==t2){
        return s+t.substr(t1.size());
    }
   }
   return s+t;
  
}
string helper(string &a,string &b,string &c){
    string t1=add(a,b);
    string t2=add(b,a);
    string s1=getmin(add(t1,c),add(c,t1));
    string s2=getmin(add(t2,c),add(c,t2));
    return getmin(s1,s2);
}
    string minimumString(string a, string b, string c) {
       n=a.size();
       m=b.size();
       l=c.size();
       string s=getmin(helper(a,b,c),helper(b,c,a));
       s=getmin(s,helper(c,a,b));
       return s;

    }
};