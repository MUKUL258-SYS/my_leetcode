class Solution {
public:
int min_steps(string s,string t){
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        int j=i;
        while(s[j]!=t[i])j++;
        while(j>i){
            swap(s[j],s[j-1]);
            j--;
            ans++;
        }

    }
    return ans;
}
    int getMinSwaps(string num, int k) {
        string temp=num;
        while(k--){
            next_permutation(temp.begin(),temp.end());
        }
        return min_steps(num,temp);
    }
};