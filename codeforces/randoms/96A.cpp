#include<bits/stdc++.h>
#include <string>

using namespace std;

int main(){

    string players;

    cin>>players;
    
    int count = 1;

    bool flag = false;

    for(int i=0; i<players.length()-1; i++){
        if(players[i]==players[i+1]){
            count++;
        }else{
            count=1;
        }

        if(count==7){
            cout<<"YES\n";
            flag = true;
            break;
        }
    }

    if(!flag){
        cout<<"NO\n";
    }

    // cout<<players<<"\n";

    return 0;
}