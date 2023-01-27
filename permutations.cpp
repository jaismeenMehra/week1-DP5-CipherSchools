class Solution {
private:
    void permute(vector<int>& nums,vector<vector<int>> &res,vector<int> &ans,int &chosenBits) {
        int nlen=nums.size();
        if(ans.size()==nlen){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nlen;i++){
            if(!(chosenBits&(1<<i))){
                ans.push_back(nums[i]);
                chosenBits=chosenBits | (1<<i);
                permute(nums,res,ans,chosenBits);
                chosenBits=chosenBits & ~(1<<i);
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        //1 <= nums.length <= 6
        int chosenBits=0;
        permute(nums,res,tmp,chosenBits);
        return res;
    }
};