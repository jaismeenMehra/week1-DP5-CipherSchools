class Solution {
private:
    bool canMakeWord(vector<vector<char>>& board,vector<int>& visited,const string &word,int si,int sj,int wi){
        if(wi==word.length()){
            return true;
        }
        if( si<0 || sj<0 || sj>=board[0].size() || si>=board.size() ||(board[si][sj]!=word[wi]) || (visited[si]&(1<<sj))){
            return false;
        }
        visited[si]=visited[si] | 1<<sj;
        bool ans= canMakeWord(board,visited,word,si+1,sj,wi+1) ||
        canMakeWord(board,visited,word,si-1,sj,wi+1) ||
        canMakeWord(board,visited,word,si,sj+1,wi+1) ||
        canMakeWord(board,visited,word,si,sj-1,wi+1);
        visited[si]=visited[si] & ~(1<<sj);
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        vector<int> visited(rows,0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    if(canMakeWord(board,visited,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};