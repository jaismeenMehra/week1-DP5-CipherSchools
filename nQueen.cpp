class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> allPossibleAnswers;
        vector<string> ans;
        for(int i=1;i<=n;i++)
            ans.push_back(string(n,'.'));
        
        help(allPossibleAnswers,0,ans);
        return allPossibleAnswers;
    }
    private:
    void help( vector<vector<string>> &res,int rowIdx,vector<string> &ans){
        if(rowIdx==ans.size()){
            res.push_back(ans);
            return;
        }
        for(int j=0;j<ans[rowIdx].size();j++){
            if(safe(rowIdx,j,ans)){
                ans[rowIdx][j]='Q';
                help(res,rowIdx+1,ans);
                ans[rowIdx][j]='.';
            }
        }
    }
    bool safe(int row,int col ,vector<string> &v){
        int x=row,y=col;
        while(x>=0 && y>=0){//up left diagonal check
            if(v[x][y]=='Q') 
                return false;

            x--;
            y--;
        }
        x=row,y=col;
        while(x>=0 && y>=0){//up
            if(v[x][y]=='Q') 
                return false;

            x--;
        }
        x=row,y=col;
        while(x>=0 && y>=0){//right diagonal check
            if(v[x][y]=='Q') 
                return false;

            x--;
            y++;
        }
        return true;
    }
};