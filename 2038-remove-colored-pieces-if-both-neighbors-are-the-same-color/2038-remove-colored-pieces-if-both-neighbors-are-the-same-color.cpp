class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int cnta=0,cntb=0;
        colors[0]=='A'?cnta++:cntb++;
        int vala=0;
        int valb=0;
        
        for(int i=1;i<n;i++){
           if(colors[i]==colors[i-1]){
                  if(colors[i]=='A')cnta++;
                  else cntb++;
           }
           else{
                if(colors[i-1]=='A'){vala+=(cnta>=2?cnta-2:0);
                       cnta=0;
                       cntb=1;
                }
                else { valb+=(cntb>=2?cntb-2:0);
                   cntb=0;
                   cnta=1;
                }
                

           }
        }
        
       /* if(colors[i]==colors[i-1]){
                  if(colors[i]=='A'){
                    cnta++;
                    vala+=(cnta>=2?cnta-2:0);
                  }
                  else {
                    cntb++;
                    valb+=(cntb>=2?cntb-2:0);
                  }
           }
        */
        if(cnta>=2){
            vala+=(cnta>=2?cnta-2:0);
        }
        else if(cntb>=2){
              valb+=(cntb>=2?cntb-2:0);
        }
        

        return vala>valb;
    }
};