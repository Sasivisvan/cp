#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    
    // Step 1: Check if already sorted
    sort(b.begin(), b.end());
    bool is_sorted = true;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            is_sorted = false;
            break;
        }
    }

    if(is_sorted) {
        cout << -1 << "\n";
        return;
    }

    // Step 2: Calculate max k
    long long min_val = b[0];
    long long max_val = b[n-1];
    long long ans = 2e9; // Initialize with a value larger than any possible gap

    for(int i = 0; i < n; i++) {
        // Only check constraints for elements that are NOT in their correct sorted position
        if(a[i] != b[i]) {
            // Can this element reach the Min? Or the Max?
            // We take the BEST option for this specific element.
            long long reach = max(a[i] - min_val, max_val - a[i]);
            
            // The global k is limited by the "weakest" element (smallest reach)
            ans = min(ans, reach);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}