#include<bits/stdc++.h>

using namespace std;

int main(){

    int tc;
    cin >> tc;
    while(tc--){
        int x = 0;
        int y =0;
        int n;
        cin >> n;
        vector<int> arr;
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        int common;
        if(arr[0]==arr[1]){
            common = arr[0];
        }else if(arr[0]==arr[2]){
            common = arr[0];
        }else{
            common = arr[1];
        }

        for(int i=0; i<n; i++){
            if(arr[i]!=common){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}
