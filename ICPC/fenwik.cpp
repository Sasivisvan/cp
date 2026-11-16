#include <vector>

struct FenwickTree {
    int n;
    std::vector<long long> bit; // long long to prevent WA on large prefix sums

    FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    // O(N) optimal construction
    FenwickTree(const std::vector<long long>& a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; i++) {
            bit[i + 1] += a[i]; // 1-based indexing internally
            int parent = (i + 1) + ((i + 1) & -(i + 1));
            if (parent <= n) {
                bit[parent] += bit[i + 1]; // Push partial sum to parent
            }
        }
    }

    long long sum(int idx) {
        long long ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    long long sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, long long delta) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }
};