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

    int n;
    cin >> n;

    int ans = 0;
    while(n!=0){
        if(n%2==0)n=n/2;
        else {ans++; n--;}
    }
    cout<<ans<<endl;
    
}
