#include <deque>
#include<bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;

void pa(vector<int>arr){
    for(auto a:arr){
        cout<<a<<" ";
    }
    cout<<endl;
}

void pma(vector<vector<int>>arr){
    for(auto a:arr){
        for(auto b: a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){

    int tc;
    cin >> tc;
    while(tc--){

    int  n;
    cin >> n;
    int temp = n;
    vector<int>arr;
    bool found = false;

    for(int i=1; i<=n; i++){
        arr.push_back(i);
    }
    if(n==1 || n==2 || n==3 )cout<< -1 <<endl;
    else{
        arr[3] = 1;
        arr[0] = 4;
        pa(arr);
    } 

    }
}
