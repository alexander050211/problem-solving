#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define F first
#define S second
typedef pair<ll, ll> pll;
#define mod 998244353
#define INF (ll)1e15
#define pb push_back
pll dp[1000005];
ll ppow(ll a, ll b)
{
  ll ret = 1;
  ll aa = a;
  while (b)
  {
    if (b % 2)
      ret = (ret * aa) % mod;
    aa = (aa * aa) % mod;
    b /= 2;
  }
  return ret % mod;
}
ll inv(ll a)
{
  return ppow(a, mod - 2) % mod;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin >> n;
  for (int i = n - 1; i >= 0; i--)
  {
    pll t = dp[i + 1];
    dp[i].F = (((i * inv(n + i)) % mod) * t.F) % mod;
    dp[i].F = (dp[i].F + (((n * inv(n + i)) % mod) * t.S)) % mod;
    dp[i].S = (((i * inv(n + i)) % mod) * t.S) % mod;
    dp[i].S = (dp[i].S + (((n * inv(n + i)) % mod) * t.F)) % mod;

    ll t1 = (i * n) % mod;
    ll t2 = (inv(n - i) * inv(n + i)) % mod;
    dp[i].F = (dp[i].F + t1 * (t2)) % mod;

    t1 = ppow(i, 2);
    dp[i].S = (dp[i].S + t1 * (t2)) % mod;
  }
  cout << dp[0].F << ' ' << dp[0].S << endl;
  return 0;
}