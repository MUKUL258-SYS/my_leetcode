class Spreadsheet {
public:
vector<vector<int>>vp;
int rows;
    Spreadsheet(int rows) {
        this->rows=rows;
        vp.resize(rows,vector<int>(26,0));
    }
    pair<int,int>func(string cell){
        char ch=cell[0];
        cout<<cell<<endl;
        int row=stoi(cell.substr(1));
       if(row>0&&row<=rows)return {row-1,ch-'A'};
       return {-1,-1};

    }
    void setCell(string cell, int value) {
        pair<int,int>p=func(cell);
        if(p.first!=-1){
            int x=p.first;
            int y=p.second;
            vp[x][y]=value;
        }
    }
    
    void resetCell(string cell) {
       pair<int,int>p=func(cell);
        if(p.first!=-1){
            int x=p.first;
            int y=p.second;
            vp[x][y]=0;
        }
    }
    
    int getValue(string formula) {
        auto idx=formula.find('+');
         int v1,v2;
        string cell1=formula.substr(1,idx-1);
        string cell2="";
        if(idx+1<formula.size())cell2=formula.substr(idx+1);
        if(cell1[0]>='A'&&cell1[0]<='Z'){
        pair<int,int>p=func(cell1);
            if(p.first!=-1){
            int x=p.first;
            int y=p.second;
            v1=vp[x][y];
        }
        }
        else{
            v1=stoi(cell1);
        }
        if(cell2[0]>='A'&&cell2[0]<='Z'){
        pair<int,int>p=func(cell2);
            if(p.first!=-1){
            int x=p.first;
            int y=p.second;
            v2=vp[x][y];
        }
        }
        else{
            v2=stoi(cell2);
        }
        return v1+v2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */