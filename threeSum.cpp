class Solution {
private:
    int binSearch(vector<int> &nums,int start,int end,int target){
        int l=start;
        int h=end-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int len=nums.size();
    if(nums.size()<3)
       return {};
   sort(nums.begin(),nums.end());
   
   set<vector<int>> triplets;
        
  for(int i=0;i<len-2;i++){
        int p=i;
        int q=i+1;
        int lastIndex=len;
        while(q<len){
            
            int rem=-(nums[p]+nums[q]);
            int idx=binSearch(nums,q+1,lastIndex,rem);
            if(idx>=0){
                lastIndex=idx;
                triplets.insert({nums[p],nums[q],nums[idx]});
            }
            q++;
        }
    }
    vector<vector<int>> trips;
    trips.assign(triplets.begin(), triplets.end());
    return trips;
    }
};