#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;


    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());


    int lb=0;

    int p1,p2;
    p1 =0;p2 = arr.size()-1;
    int count = 0; 
    int c = 0;
    while(true){
        lb = 0;
        int mc = 0;
        if((lb+arr[p2] )<= k && p1<=p2 && mc<2){
            lb += arr[p2];
            p2--;
            mc++;
            c++;
        }
        if((lb+arr[p2] )<= k && p1<=p2 && mc<2){
            lb += arr[p2];
            c++;
            p2--;
            mc++;
        }
        if((lb+arr[p1]) <= k && p1<=p2 && mc<2){
            lb+=arr[p1];
            p1++;
            c++;
            mc++;
        }
        if((lb+arr[p1]) <= k && p1<=p2 && mc<2){
            lb+=arr[p1];
            p1++;
            c++;
            mc++;
        }
        // cout<<lb<<"\n";
        count++;
        if(p1>=p2)break;
    }
    // cout <<c<<"\n";
    if((arr.size()-c) == 0) cout<<count<<"\n";
    if((arr.size()-c) == 1) cout<<count+1<<"\n";

    return 0;
}