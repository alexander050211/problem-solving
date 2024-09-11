#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define mod 998244353
ll dp[200005], s = 1;
unordered_map<ll, ll> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n + 1, 0), sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    mp[0] = 1;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (s - mp[sum[i] - k] + mod) % mod;
        s = (s + dp[i]) % mod;
        mp[sum[i]] = (mp[sum[i]] + dp[i]) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}