class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<int> spiralOrder;

        int sc=0;
        int ec=cols-1;
        int sr=0;
        int er=rows-1;

        while(sr<=er && sc<=ec){
            for(int i=sc;i<=ec;i++){
                spiralOrder.push_back(matrix[sr][i]);
            }
            sr++;
            for(int j=sr;j<=er;j++){
                spiralOrder.push_back(matrix[j][ec]);
            }
            ec--;
            for(int k=ec;er!=(sr-1) && k>=sc;k--){
                spiralOrder.push_back(matrix[er][k]);
            }
            er--;
            for(int l=er;sc!=(ec+1) && l>=sr;l--){
                spiralOrder.push_back(matrix[l][sc]);
            }
            sc++;
        }
        return spiralOrder;
    }
};