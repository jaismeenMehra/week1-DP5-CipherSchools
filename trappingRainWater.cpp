class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        int lmax=0,rmax=0;
        int maxWater=0;

        int i=0;
        int j=len-1;
        while(i<j){
            lmax=max(lmax,height[i]);
            rmax=max(rmax,height[j]);

            if(lmax<rmax){
                maxWater+=(lmax-height[i])*1;
                i++;
            }else{
                maxWater+=(rmax-height[j])*1;
                j--;
            }
        }
        return maxWater;
    }
};