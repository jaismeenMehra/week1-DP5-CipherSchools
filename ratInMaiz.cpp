class Solution{
private:
    void findPath(vector<vector<int>> &m, int n,vector<int> &visited,vector<string> &ans,string &temp,int i,int j) {
        if(i<0 || j<0 || i>=n || j>=n || (visited[i] & 1<<j) || m[i][j]==0){
            return;
        }
        if(i==j && i==n-1){
            ans.push_back(temp);
            return;
        }
        visited[i]=visited[i] | 1<<j;
        temp.push_back('R');
        findPath(m,n,visited,ans,temp,i,j+1);
        temp.pop_back();
        
        temp.push_back('L');
        findPath(m,n,visited,ans,temp,i,j-1);
        temp.pop_back();
        
        temp.push_back('U');
        findPath(m,n,visited,ans,temp,i-1,j);
        temp.pop_back();
        
        temp.push_back('D');
        findPath(m,n,visited,ans,temp,i+1,j);
        temp.pop_back();
        visited[i]=visited[i] & ~(1<<j);
    }
public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // 2 ≤ N ≤ 5
        vector<int> visited(n,0);
        vector<string> ans;
        string temp="";
        findPath(m,n,visited,ans,temp,0,0);
        return ans;
    }
};