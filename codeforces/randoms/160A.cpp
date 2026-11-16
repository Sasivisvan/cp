#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> nums;

    for(int i = 0; i<n; i++){
        int temp ;
        cin>>temp;
        nums.push_back(temp);
    }

    sort(nums.begin(), nums.end());

    int total = accumulate(nums.begin(), nums.end(), 0);
    int rs = 0;

    for(int i=n-1; i>=0; i--){
        rs += nums[i];
        if(rs > (total-rs)){
            cout<<n-i<<"\n";
            break;
        }
    }
    return 0;
}