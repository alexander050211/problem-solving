#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define mod 998244353
ll n;
ll arr[200005];
vector<ll> brr;
ll gcd(ll x, ll y)
{
  if (!y)
    return x;
  return gcd(y, x % y);
}
ll ppow(ll a, ll b)
{
  ll ret = 1;
  ll aa = a;
  while (b)
  {
    if (b & 1)
    {
      ret = (ret * aa) % mod;
    }
    b >>= 1;
    aa = (aa * aa) % mod;
  }
  return ret % mod;
}
ll inv(ll a)
{
  return ppow(a, mod - 2) % mod;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  ll temp = 1;
  for (int i = 1; i < n; i++)
  {
    if (arr[i] == arr[i - 1])
      temp++;
    else
    {
      brr.push_back(temp);
      temp = 1;
    }
  }
  brr.push_back(temp);
  for (auto x : brr)
  {
    if (x % 2 == 0)
    {
      cout << 0 << endl;
      return 0;
    }
  }
  if (arr[0] == 0)
  {
    cout << 0 << endl;
    return 0;
  }
  sort(brr.begin(), brr.end());
  ll ans = 1;
  ll m = 0;
  for (auto x : brr)
  {
    ll t = x / 2;
    if (!t)
      continue;
    m += t;
    if (t == 1)
      continue;
    ans = (ans * (t + 1)) % mod;
    ans = (ans * inv(t - 1)) % mod;
  }
  for (int i = 1; i <= m; i++)
    ans = (ans * i) % mod;
  cout << ans << endl;
  return 0;
}