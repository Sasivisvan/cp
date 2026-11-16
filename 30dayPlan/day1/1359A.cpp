#include<bits/stdc++.h>

using namespace std;

int main(){

    int tc;
    cin >> tc;
    while(tc--){
        long long int  x = 0;
        long long int  y =0;
        long long int  n;
        long long int m;
        long long int  k;

        cin >> n;
        cin >> m;
        cin >> k;

        int k2 = k - 1;
        int n2 = n - min(m, n/k);
        int m2 = m - min(m, n/k);

        // cout << n2 << " " <<  m2 << " "<<  k2<<endl;
        int next = ceil((m2*1.0)/(k2*1.00));
        cout<< abs(min(m, n/k) - next)<<endl;
    }

}
