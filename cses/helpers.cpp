#include<bits/stdc++.h>

using namespace std;


int bs(vector<int>arr, int val){
    int hi = arr.size()-1;
    int low = 0;
    int mid;

    while(low<hi){
        mid = (low+hi)/2;

        if (arr[mid] == val){
            return 0;
        }
        if(val>arr[mid]){
            low = mid+1;
        }else{
            hi = mid-1;
        }
    }

    return abs(arr[mid] - val);
}

void printarr(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<< " ";
    }
    cout<<"\n";
    return ;
}



