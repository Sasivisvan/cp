#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    arr.push_back(temp);
  }

//   unordered_set<int> us;

//   for (int i = 0; i < n; i++) {
//     us.insert(arr[i]);
//   }

//   cout << us.size();

  sort(arr.begin(), arr.end());

  int c =1;
//   if(arr[0]!=arr[1])c++;
//   if(arr[arr.size()-2]!=arr[arr.size()-1])c++;

  for(int i=0; i<n-1; i++){
    if(arr[i+1]!= arr[i]){
        c+=1;
    }
  }

  cout<<c<<"\n";

  return 0;
}