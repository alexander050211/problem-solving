#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

// Segment Tree to find the index of the minimum value in a range.
// This is used to efficiently find the next conflict point.
vector<int> seg_tree;
vector<pair<int, int>> initial_values;
int N_seg;

void build(int node, int start, int end) {
    if (start == end) {
        seg_tree[node] = start;
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    if (initial_values[seg_tree[2 * node]].first < initial_values[seg_tree[2 * node + 1]].first) {
        seg_tree[node] = seg_tree[2 * node];
    } else {
        seg_tree[node] = seg_tree[2 * node + 1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l || l > r) {
        return -1;
    }
    if (l <= start && end <= r) {
        return seg_tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    if (initial_values[p1].first < initial_values[p2].first) {
        return p1;
    } else {
        return p2;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    vector<int> a(n + 1);
    vector<int> posA(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        posA[a[i]] = i;
    }

    vector<int> b(n + 1);
    vector<int> posB(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        posB[b[i]] = i;
    }

    vector<ll> prefix_pos_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_pos_sum[i] = prefix_pos_sum[i - 1];
        if (v[a[i]] > 0) {
            prefix_pos_sum[i] += v[a[i]];
        }
    }
    
    // Setup for Segment Trees
    N_seg = n;
    initial_values.assign(n, {0,0});
    seg_tree.assign(4 * n, 0);

    // Build Segment Tree for Alice's perspective (finding k)
    for(int i = 0; i < n; ++i) initial_values[i] = {posB[a[i+1]], i + 1};
    build(1, 0, n-1);
    auto find_k = [&](int pa, int pb) {
        int low = pa - 1, high = n - 1, ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int min_pos_idx = query(1, 0, n - 1, pa - 1, mid);
            if (initial_values[min_pos_idx].first >= pb) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int min_pos_idx = query(1, 0, n - 1, pa - 1, ans);
        return initial_values[min_pos_idx].second;
    };
    
    // Build Segment Tree for Bob's perspective (finding p)
    for(int i = 0; i < n; ++i) initial_values[i] = {posA[b[i+1]], i + 1};
    build(1, 0, n - 1);
    auto find_p = [&](int pa, int pb) {
        int low = pb - 1, high = n - 1, ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int min_pos_idx = query(1, 0, n - 1, pb - 1, mid);
            if (initial_values[min_pos_idx].first >= pa) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int min_pos_idx = query(1, 0, n - 1, pb - 1, ans);
        return initial_values[min_pos_idx].first;
    };


    ll total_value = 0;
    int pa = 1, pb = 1;

    while (pa <= n && pb <= n) {
        if(a[pa] == b[pb]) {
            if(v[a[pa]] > 0) total_value += v[a[pa]];
            pa++; pb++;
            continue;
        }

        int k = find_k(pa, pb);
        int p = find_p(pa, pb);

        if (k < p) {
            total_value += prefix_pos_sum[k] - prefix_pos_sum[pa - 1];
            pb = posB[a[k]] + 1;
            pa = k + 1;
        } else {
            total_value += prefix_pos_sum[p] - prefix_pos_sum[pa - 1];
            int l = posA[b[posA[a[p]]]];
            pb = posA[b[posA[a[p]]]]+1; // This part is tricky. A simpler advance is needed.
            
            // Simplified advance logic
            int l_idx = -1;
            for(int i = pb; i <= n; ++i) { if(posA[b[i]] == p) {l_idx = i; break;} }
            pb = l_idx + 1;
            pa = p + 1;
        }
    }

    cout << total_value << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}