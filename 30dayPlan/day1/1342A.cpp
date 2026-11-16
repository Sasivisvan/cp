#include<bits/stdc++.h>

using namespace std;

int main(){

    int tc;
    cin >> tc;
    // vector<int> arr(1,0);
    // int k=1;
    // int i=0;
    // while(i<1000000000){

    //     arr.push_back(k+arr[arr.size()-1]);
    //     k=k*2;
    //     // cout << arr[arr.size()-1]<<" ";
    //     i = arr[arr.size()-1];
    // }
    // cout <<  endl;
    // cout << arr.size()<<endl;
    while(tc--){
        long long int  x = 0;
        long long int  y =0;
        long long int  a;
        long long int  b;
        cin >> x;
        cin >> y;
        cin >> a;
        cin >> b;

        b = min(2*a, b);

        long long int ans = 0;
        if(x<0 && y<0){
            ans = ans + b*(abs(max(x,y)));
            int t = max(x,y);
            x = x + t;
            y = y + t;
        }else if(x>0 && y>0){
            ans = ans + b*(min(x,y));
            int t = min(x,y);
            x = x - t;
            y = y - t;
        }

        cout << abs(x)*a + abs(y)*a + ans<< endl;


    }
}
