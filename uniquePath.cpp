class Solution {
private:
    int uniquePathsIII(vector<vector<int>> &grid,vector<vector<bool>> &visited,int si,int sj,int &empty){
        int rows=grid.size();
        int cols=grid[0].size();

        if(si<0 || si>=rows || sj<0 || sj>=cols || visited[si][sj] || grid[si][sj]==-1){
            return 0;
        }
        
        if(grid[si][sj]==2){
            if(empty==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        visited[si][sj]=true;
        empty--;
        int ans=uniquePathsIII(grid,visited,si,sj+1,empty)+
               uniquePathsIII(grid,visited,si,sj-1,empty)+
               uniquePathsIII(grid,visited,si-1,sj,empty)+
               uniquePathsIII(grid,visited,si+1,sj,empty);
        empty++;
        visited[si][sj]=false;
        return ans;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int empty=0;
        int si=-1;
        int sj=-1;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }else if(grid[i][j]==0){
                    empty++;
                }
            }
        }
        empty++; // for 1
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        return uniquePathsIII(grid,visited,si,sj,empty);
    }
};