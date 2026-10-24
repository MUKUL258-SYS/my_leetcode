class Solution {
public:
    int countDaysTogether(string aa, string la, string ab,string lb) {
        int m1=stoi(aa.substr(0,2));
        int m2=stoi(la.substr(0,2));
        int m3=stoi(ab.substr(0,2));
        int m4=stoi(lb.substr(0,2));
       // if(m3>m2 || m1>m4)return 0;
        int d1=stoi(aa.substr(3));
        int d2=stoi(la.substr(3));
        int d3=stoi(ab.substr(3));
        int d4=stoi(lb.substr(3));
       // if(d3>d2 || d1>d4)return 0;
        
        vector<int>arr={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=1;i<12;i++){
            arr[i]+=arr[i-1];
        }
        int day1=(m1>=2 ?arr[m1 -2]:0)+d1;
         int day2=(m2>=2 ?arr[m2 -2]:0)+d2; 
         int day3=(m3>=2 ?arr[m3 -2]:0)+d3;
          int day4=(m4>=2 ?arr[m4 -2]:0)+d4;
           cout<<day1<<" "<<day2<<" "<<day3<<" "<<day4<<endl;;
         if(day3>day2 || day1>day4)return 0;
          int maxi=max(day1,day3);
          int mini=min(day2,day4);
         // cout<<mini<<" "<<maxi<<endl;
        // cout<<day1<<" "<<day2<<" "<<day3<<" "<<day4<<endl;
          return mini-maxi+1;

    }
};