#include<bits/stdc++.h>

using namespace std;

int main(){

    int tc;
    cin >> tc;
    while(tc--){
        long long int  x = 0;
        long long int  y =0;
        long long int  a;
        long long int  b;

        int n;
        cin >> n;

        long long int sums = 0;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            sums += temp;
        }

        if((long long int)sqrt(sums)*(long long int)sqrt(sums) == sums){
            cout<<"YES"<<endl;
        }else{
            cout << "NO" << endl;
        }


    }
}
