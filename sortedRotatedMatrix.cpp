class Solution {
public:
//(1 <= k < nums.length  ... k is not zero
    int search(vector<int>& v, int target) {
        int low=0;
    int high=v.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        
       if(v[mid]==target){
           return mid;
       }
        else if(v[mid]>=v[low]){//first half is sorted
            if(target<v[mid] && target>=v[low]){
                high=mid-1;
            }else{
                low=mid+1;//jump to second half
            }
        }else if(v[high]>=v[mid+1]){//second half is sorted
            if(target<=v[high] && target>v[mid]){
                low=mid+1;
            }else{
                high=mid-1;//jump to previous half
            }
        }
    }
    return -1;
    }
};