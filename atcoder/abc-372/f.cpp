#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define mod 998244353
ll n, m, k;
ll dp[400005];
pll brr[55];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++)
    cin >> brr[i].F >> brr[i].S;
  for (int i = 0; i < m; i++)
  {
    brr[i].F--;
    brr[i].S--;
  }
  brr[m++].F = n - 1;

  dp[k] = 1;
  for (int i = 1; i <= k; i++)
  {
    vector<pll> crr = vector<pll>();
    for (int j = 0; j < m; j++)
      crr.push_back({k - i + brr[j].S, dp[k - i + 1 + brr[j].F]});
    for (auto x : crr)
      dp[x.F] = (dp[x.F] + x.S) % mod;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans = (ans + dp[i]) % mod;
  cout << ans << endl;
  return 0;
}