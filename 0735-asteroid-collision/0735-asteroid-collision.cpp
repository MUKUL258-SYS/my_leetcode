class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>s;
        int n=a.size();
        s.push(a[0]);
        for(int i=1;i<n;i++){
           if(i==1&&a[i]>0){
               s.push(a[i]);
               continue;
           }
           if(s.size()&&a[i]<0&&s.top()>0){
            if(abs(a[i])==abs(s.top())){
                s.pop();
            }
            else{
                 while(s.size()&&a[i]<0&&s.top()>0&&abs(a[i])>s.top()){
                    s.pop();
                 }
                 if(s.size()&&s.top()>0&&a[i]<0){
                    if(s.top()==abs(a[i]))s.pop();
                 }
                else if(s.empty()||(s.top()<0))s.push(a[i]);
            }
           }else{
            s.push(a[i]);
           }
           
        }
        vector<int>v;
        while(s.size()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};