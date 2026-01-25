class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res(n-k+1,vector<int>(m-k+1,0));
        for(int i=0;i+k<=n;i++){
            for(int j=0;j+k<=m;j++){
                int mini=INT_MAX;
               vector<int>temp;
                for(int u=i;u<i+k;u++){
                    for(int v=j;v<j+k;v++){
                        temp.push_back(grid[u][v]);
                      //cout<<grid[u][v]<<" ";
                    }
                   // cout<<endl;
                }
                sort(temp.begin(),temp.end());
                if(temp.size()==1){res[i][j]=0;
                   continue;
                }
                int cnt0=0;
                if(temp[0]==0)cnt0++;
                for(int l=1;l<temp.size();l++){
                //   cout<<temp[l]<<" ";
                 if(temp[l]==0)cnt0++;
                   if(temp[l]==temp[l-1])continue;
                    mini=min(mini,abs(temp[l]-temp[l-1]));
                    // if(temp[i]==0)cnt0++;
                }
             //   cout<<endl;
           // cout<<mini<<endl;
           if(cnt0==temp.size())res[i][j]=0;
           else     res[i][j]=mini;

            }
        }
        return res;
    }
};