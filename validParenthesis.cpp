class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
                p.push(s[i]);
            else{
                if(p.empty())
                    return false;
                char c=p.top();
                p.pop();
                if(!(s[i]-c==1 || s[i]-c==2))
                    return false;
            }
        }
        if(!p.empty())
            return false;
        else
            return true;
    }
};