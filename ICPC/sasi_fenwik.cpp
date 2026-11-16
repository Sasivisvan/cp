#include<vector>
#include<bits/stdc++.h>

using namespace std;

struct FWT{

    int n;
    vector<long long> bit;
    
    FWT(int n): n(n), bit(n+1, 0) {}

    FWT(const vector<long long>& a): FWT(a.size()){
        for (int i=1; i<=n; i++) {
            bit[i] = a[i];
        }

        for(int i=1; i<=n; i++){
            int parent = i + (i&-i);
            if (parent<=n){
                bit[parent] += bit[i];
            }
        }
    }

    void add(int idx, int val){
        for(int idx;; )
    }


};