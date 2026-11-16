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

    int ans = arr.size()-1;
    while(ans-1 >= 0 && arr[ans]<=arr[ans-1])ans-=1;
    while(ans-1 >= 0 &&  arr[ans]>=arr[ans-1])ans-=1;
    cout << ans <<endl;
    }
}
