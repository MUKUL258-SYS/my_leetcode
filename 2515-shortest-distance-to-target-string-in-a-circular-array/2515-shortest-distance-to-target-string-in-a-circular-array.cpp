class Solution {
public:
int min_steps(vector<string>&words,string t,int s){
    int n=words.size();
    int i=s;
    int cnt1=0;
    int cnt2=0;
bool f1=false;
bool f2=false;
    while(i>=0){
        if(words[i]==t){
            //cnt1++;
            f1=true;
            break;
        }
        cnt1++;
        i--;
    }
    i=s;
    while(i<n){
        if(words[i]==t){
            //cnt2++;
            f2=true;
            break;
        }
        cnt2++;
        i++;
    }
    if(!f1)cnt1=INT_MAX;
    if(!f2)cnt2=INT_MAX;
    return min(cnt1,cnt2);
}
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        bool f=false;
        for(auto i:words){
            if(i==target){
                f=true;
                break;
            }
        }
        if(!f)return -1;
        if(words[startIndex]==target)return 0;
        int n=words.size();
        for(int i=0;i<n;i++){
            words.push_back(words[i]);
        }
        cout<<min_steps(words,target,startIndex)<<endl;
        cout<<min_steps(words,target,startIndex+n)<<endl;
        return min(min_steps(words,target,startIndex),min_steps(words,target,startIndex+n));

    }
};