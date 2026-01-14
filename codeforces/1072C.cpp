#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin >> n >> k;
        queue<int>q;
        q.push(n);
        int i=0;
        int ans = 0;
        unordered_set<int> visited;
        visited.insert(n);
        while(true){
            // cout<<"running<<endl;";
            int size = q.size();
            if(size==0)break;
            while(size--){
                int val = q.front();
                q.pop();
                if(val==k){
                    cout<<i<<endl;
                    q = queue<int>();
                    ans =1;
                    break;
                }
                if(val%2==0 && val/2 >= k && visited.find(val/2) == visited.end()){
                    visited.insert(val/2);
                    q.push(val/2);
                }
                else if(val%2==1&&val/2+1>=k){
                    if(visited.find(val/2) == visited.end())q.push(val/2);
                    if(visited.find(val/2 +1 ) == visited.end())q.push(val/2 + 1);
                }
            }
            i++;
        }
        if(!ans){
            cout<<-1<<endl;
        }
    }
}
