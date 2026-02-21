class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        /*vector<pair<int,int>>v;
        //int n=s.size();
        int cnt=1;
        s="1"+s;
        s=s+"1";
        int n=s.size();
        cout<<s<<endl;
        for(int i=1;i<n;i++){
           if(s[i]==s[i-1]){
              cnt++;
           }
           else{
             v.push_back({s[i-1]-'0',cnt});
             cnt=1;
           }
        }
       // v.push_back({s.back()-'0',cnt});
        for(auto i:v){
            cout<<i.first<<" "<<i.second<<endl;
        }
        vector<pair<int,int>>temp;
        if(v[0].second>1)temp.push_back({v[0].first,v[0].second-1});
        for(auto i:v){
            temp.push_back(i);
        }
        if(temp.back().second==1)temp.pop_back();
        else temp.back().second=temp.back().second-1;
        v=temp;
        n=v.size();
        if(n==1&&v[0].first==0)return 0;
        if(n==1&&v[0].first==1)return v[0].second;
        if(n==2){
            if(v[0].first==1)return v[0].second;
            else return v[1].second;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            if(v[i].first==1&&i>=1&&i+1<n){
              int value=v[i].second;
               if(i-1>=0){value+=(v[i-1].second);
               if(i-1==0)value--;
              }
              if(i+1<n){value+=(v[i+1].second);
               if(i+1==(n-1))value--;
              }
              
            //  value+=v[i-1].second;
            //  value+=v[i+1].second;
             // if(i-1==0)value--;
            //  if(i+1==(n-1))value--;
              if(i-2>=0){value+=(v[i-2].second);
               if(i-2==0)value--;
              }
              if(i+2<n){value+=(v[i+2].second);
                 if(i+2==(n-1))value--;
              }
              maxi=max(maxi,value);
            }
        }
        return maxi-1;
        */
        int n=s.size(),i=0,one=0,zero=0;
        int curr=0,prev=0;
        while(i<n&&s[i]=='1')one++,i++;
        while(i<n&&s[i]=='0')prev++,i++;
        while(i<n){
            while(i<n&&s[i]=='1')one++,i++;
            if(i==n)break;
            while(i<n&&s[i]=='0')curr++,i++;
            zero=max(zero,prev+curr);
            prev=curr;
            curr=0;
        }
        return one+zero;



    }
};