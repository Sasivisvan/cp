#include<bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n,a,b;
        cin >> n ;
        cin >> a;
        cin >> b;
        //a -> 97, z -> 122

        string ans;
        int i = 0;
        while(n--){
            ans += (char)(97+i);
            if(i==b-1){
                i=-1;
            }
            i+=1;

        }
        cout <<ans<<endl;

        // cout << (int)'a' << " " << (int)'z'<<endl;


    }
    return 0;
}
