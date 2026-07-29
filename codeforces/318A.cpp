#include <bits/stdc++.h>


using namespace std;

int main(){

    long long int n, k;
    cin>>n;
    cin>>k;
    vector<int> nums;

    if(n%2==0){
        if(k<=n/2){
            cout<<2*k-1;
        }else{
            cout<<2*(k-(n/2));
        }
    }
    if(n%2==1){
        if(k<=n/2+1){
            cout<<2*k-1;
        }else{
            cout<<2*(k-(n/2)-1);
        }
    }
    cout<<"\n";
    return 0;
}