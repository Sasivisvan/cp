#include<bits/stdc++.h>

using namespace std;

int main(){

    int tc;
    cin >> tc;
    while(tc--){

    vector<string> ans;
    string s;
    cin >> s;

    int i = s.size()-1;
    int n = s.size();


    for(int i=0 ;i<n; i++){
        if(s[i]!='0'){
            string t(n-i-1, '0');
            ans.push_back(s[i] + t + " ");
        }
    }

    cout<<ans.size()<<endl;
    for(auto a:ans){
        cout<<a;
    }
    cout<<endl;

}
    // while(i > 1){
    //       if (s[i] == '0'){
    //           i--;
    //       }else{
    //           break;
    //       }
    // }

    // if(i==0 && s[i]!=0){
    //     cout<<"YES"<<endl;
    // }else{
    //     cout<<"NO"<<endl;
    // }

    // cout << s<<endl;

    return 0;
}
