#include<bits/stdc++.h>
using namespace std;

int binLastIndex(vector<int> &nums,int of){
  int len=nums.size();
  int low=0,high=len-1;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(nums[mid]==of){
      if(mid==len-1 || nums[mid+1]>of){
        return mid;
      }else{
        low=mid+1;
      }
    }else if(nums[mid]>of){
      high=mid-1;
    }else{
      low=mid+1;
    } 
  }
  return -1;
}

int binFirstIndex(vector<int> &nums,int of){
  int len=nums.size();
  int low=0,high=len-1;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(nums[mid]==of){
      if(mid==0 || nums[mid-1]<of){
        return mid;
      }else{
        high=mid-1;
      }
    }else if(nums[mid]>of){
      high=mid-1;
    }else{
      low=mid+1;
    } 
  }
  return -1;
}

int main(){
  // vector<int> nums{4, 4, 8, 8, 8, 15, 16, 23, 23, 42};
  // vector<int> targets{4,8,15,16,23,42,43};

  // vector<int> nums{3, 5, 5, 5, 5, 7, 8, 8};
  // vector<int> targets{3,5,7,8,0};

  vector<int> nums{3, 5, 5, 5, 5, 7, 8, 8};
  vector<int> targets{-1,3,5,7,8};
  
  for(const int target:targets){
    int fi=binFirstIndex(nums,target);
    if(fi<0){
      cout<<target<<" : Not found"<<endl;
      continue;
    }
    int li=binLastIndex(nums,target);
    cout<<(li-fi+1)<<endl;

  }
  return 0;
}

/////////optimized

#include<bits/stdc++.h>
using namespace std;

int binLastIndex(vector<int> &nums,int of,int start){
  int len=nums.size();
  int low=start,high=len-1;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(nums[mid]==of){
      if(mid==len-1 || nums[mid+1]>of){
        return mid;
      }else{
        low=mid+1;
      }
    }else if(nums[mid]>of){
      high=mid-1;
    }else{
      low=mid+1;
    } 
  }
  return -1;
}

int binFirstIndex(vector<int> &nums,int of){
  int len=nums.size();
  int low=0,high=len-1;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(nums[mid]==of){
      if(mid==0 || nums[mid-1]<of){
        return mid;
      }else{
        high=mid-1;
      }
    }else if(nums[mid]>of){
      high=mid-1;
    }else{
      low=mid+1;
    } 
  }
  return -1;
}

int main(){
  vector<int> nums{4, 4, 8, 8, 8, 15, 16, 23, 23, 42};
  vector<int> targets{4,8,15,16,23,42,43};

  vector<int> nums{3, 5, 5, 5, 5, 7, 8, 8};
  vector<int> targets{3,5,7,8,0};

  vector<int> nums{3, 5, 5, 5, 5, 7, 8, 8};
  vector<int> targets{-1,3,5,7,8};

  vector<int> nums{3};
  vector<int> targets{-1,3};
  
  for(const int target:targets){
    int fi=binFirstIndex(nums,target);
    if(fi<0){
      cout<<target<<" : Not found"<<endl;
      continue;
    }
    int li=binLastIndex(nums,target,fi);
    cout<<(li-fi+1)<<endl;

  }
  return 0;
}