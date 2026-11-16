#include<bits/stdc++.h>

using namespace std;

int main(){

    int tc;
    // cin >> tc;
    // while(tc--){
        long long int  x = 0;
        long long int  y =0;
        long long int  n;
        long long int  k;

        cin >> n;
        cin >> k;

        long long int val = 0;
        int moves = 0;

        int added = 0;
        while(true){
            val += added+1;
            added ++;
            moves++;
            if((val - (n-moves))== k){
                cout << (n-moves) <<endl;
                break;
            }
        }


}
