class Solution {
public:
    double myPow(double x, int n) {
        if(x==-1.0){
            return n&1 ? -1.0 : 1.0; 
        }else if(x==1.0){
            return 1.0;
        }else if(x==0 || n==INT_MIN){
            return 0;
        }
        else if(n==0){
            return 1.0;
        }
        
        if(n<0){
            x=1/x;
            n=-n;
        }
        double ans=1;
        while(n>0){
            if(n&1)
                ans*=x;
            x*=x;
            n>>=1;
        }

        return ans;
    }
};