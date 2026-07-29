#include <bits/stdc++.h>

using namespace std;

int main(){
    

    int tc;
    cin>>tc;
    while(tc--){
        int n;
        vector<int>arr;
        cin>>n;
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        bool flag = false;
        long long int rem = 0;
        for(int i=0; i<arr.size(); i++){
            rem += arr[i] - (i+1);
            // cout<<rem<<"  ";
            if (rem<0) {
                cout<<"NO\n";
                flag = true;
                break;
            }
        }

        if(!flag)cout<<"YES\n";
    }
    return 0;
}