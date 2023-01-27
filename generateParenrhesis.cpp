class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help(ans,n);
        return ans;
    }
private:
    void help(vector<string> &ans,int n,int o=0,int c=0,string temp=""){
        if(c==n){
            ans.push_back(temp);
        }
        else{
            if(o<n)
                help(ans,n,o+1,c,temp+'(');
            if(c<o)
                help(ans,n,o,c+1,temp+')');
        }
    }
};