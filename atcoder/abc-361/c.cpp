#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll ans = (ll)1e9;
    for (int i = 0; i <= k; i++)
        ans = min(ans, arr[i + n - k - 1] - arr[i]);
    cout << ans << endl;
    return 0;
}