#include<bits/stdc++.h>
using namespace std;
void mergeSortedArrays(vector<int> &a, int m, vector<int> &b, int n){
    int i = m-1, j=n-1, k=m+n-1;
    while (i>=0 &&  j>=0){
        if(a[i]>b[j]){
            a[k] = a[i];
            i--;
        }
        else{
            a[k]= b[j];
            j--;
        }
    }
    k--;
    while(j>=0){
        a[k] = b[j];
        j--;
        k--;
    }

    
}


int main(){
    vector<int> vec1 = {1,4,6,7,8};
    vector<int> vec2 = {2,3,5,9};
    mergeSortedArrays(vec1,5,vec2,4);


    return 0;
}