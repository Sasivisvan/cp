#include<bits/stdc++.h>

using namespace std;

int main(){

    int tc;
    cin >> tc;
    vector<int> arr(1,0);
    int k=1;
    int i=0;
    while(i<1000000000){

        arr.push_back(k+arr[arr.size()-1]);
        k=k*2;
        // cout << arr[arr.size()-1]<<" ";
        i = arr[arr.size()-1];
    }
    // cout <<  endl;
    // cout << arr.size()<<endl;
    while(tc--){
        int x = 0;
        int y =0;
        int n;
        cin >> n;

        for(int i=2; i<arr.size(); i++){
            if(n%arr[i]==0){
                cout<<n/arr[i]<<endl;
                break;
            }
        }
    }
}
