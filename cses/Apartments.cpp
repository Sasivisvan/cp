#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

// void printarr(vector<int>arr){
//     for(int i=0; i<arr.size(); i++){
//         cout<<arr[i]<< " ";
//     }
//     cout<<"\n";
//     return ;
// }

int main(){

    int n,m,k;
    cin >> n;
    cin >> m;
    cin >> k;
    
    vector<int>as;

    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        as.push_back(temp);
    }

    vector<int>das;

    for(int i=0; i<m; i++){
        int temp;
        cin>>temp;
        das.push_back(temp);
    }

    sort(as.begin(), as.end());
    sort(das.begin(), das.end());

    // printarr(as);
    // printarr(das);

    int p1,p2;
    p1 = 0;
    p2 = 0;
    int count = 0;

    while(p1<n && p2<m){
        int a = as[p1];
        int b = das[p2];

        if(abs(a-b)<=k){
            count++;
            p2++;
            p1++;
            continue;
        }

        if(a<b){
            p1++;
        }else{
            p2++;
        }

    }

    cout << count<<"\n";

    return 0;
}
