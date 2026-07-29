#include <bits/stdc++.h>


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

    // int total = accumulate(nums.begin(), nums.end(), 0);
    // int rs = 0;

    for(int i=0; i<nums.size() ; i++){
        cout<<nums[i]<<" ";
    }

    cout<<"\n";
    return 0;
}