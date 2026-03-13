class Solution {
public:
    string getHappyString(int n, int k) {
       queue<string>q;
       q.push("");
       int l=0;
       while(q.size()){
          if(l==n)break;
          int s=q.size();
          while(s--){
            string str=q.front();
            q.pop();
            for(char ch='a';ch<='c';ch++){
              if(str.size()){
                if(str.back()!=ch)q.push(str+ch);
              }
              else q.push(str+ch);
              cout<<str+ch<<endl;
            }
          }
          l++;
       }
       while(k>1&&q.size()){
        q.pop();
        k--;
       }
       return q.size()?q.front():"";


    }
};