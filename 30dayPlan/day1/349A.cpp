#include<bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

    long long int  n;

    cin >> n;

    int temp = n;
    vector<int>arr;

    int c25 = 0;
    int c50 = 0;

    bool found = false;

    while(temp--){
        int l;
        cin >> l;
        arr.push_back(l);

        int r = l;

        if(r == 25){
            c25+=1;
        }else if(r==50){
            if(c25>0){
                c25--;
                c50++;
            }else{
                cout<<"NO"<<endl;
                found = true;
                break;
            }
        }else{
            if(c50>0 && c25>0){
                c50--;
                c25--;
            }else if(c25>2){
                c25 -=3;
            }else{
                cout<<"NO"<<endl;
                found = true;
                break;
            }
        }

    }
    if(temp==-1 && !found){
        cout<<"YES"<<endl;
    }



}
