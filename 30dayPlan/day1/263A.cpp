#include<bits/stdc++.h>

using namespace std;

int main(){

    int tc;
    // cin >> tc;
    // while(tc--){
        int x = 0;
        int y =0;
        vector<vector<int>> mat;
        for(int i=0; i<5; i++){
            vector<int> row;
            for(int j=0; j<5; j++){
                int temp;
                cin>>temp;
                row.push_back(temp);
                if(temp == 1){
                    x= i;y=j;
                }
            }
            mat.push_back(row);
        }
        cout << abs(2-x)+abs(2-y) <<endl;

    // }
}
