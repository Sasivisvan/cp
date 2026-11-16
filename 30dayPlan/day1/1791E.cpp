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

    while(temp--){
        int l;
        cin >> l;
        arr.push_back(l);
    }

    //find the count of -ve nums
    // find the lowest value number
    int c=0;
    int m = abs(arr[0]);
    long long int ans = 0;
    for(auto a: arr){
        if(a<0)c++;
        if(m>abs(a))m = abs(a);
        ans += abs(a);
    }
    // cout << c << " "<< m << " "<< ans <<endl;
    if(c%2==0){cout<<ans<<endl;}
    else{cout<<ans-2*m<<endl;}
    
    }
}
