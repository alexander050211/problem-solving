#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define mod 998244353
ll n, k, ans;
vector<ll> arr, brr, bsum;
ll cnt[400005];
ll dp[200005];
ll fac[400005], facinv[400005];
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
  return ret;
}
ll inv(ll a)
{
  return ppow(a, mod - 2);
}
ll nck(ll a, ll b)
{
  if (a == b)
    return 1;
  ll ret = fac[a];
  ret = (ret * facinv[b]) % mod;
  ret = (ret * facinv[a - b]) % mod;
  return ret % mod;
}
ll nhk(ll a, ll b)
{
  return nck(a + b - 1, b);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n; i++)
    cnt[arr[i]]++;
  brr.resize(k);
  bsum.resize(k);
  ll tidx = -1;
  ll idx = 0;
  while (cnt[idx])
    idx++;
  for (int i = 0; i < k; i++)
  {
    brr[i] = idx - tidx;
    tidx = idx;
    idx++;
    while (cnt[idx])
      idx++;
  }
  bsum[0] = brr[0];
  for (int i = 1; i < k; i++)
    bsum[i] = bsum[i - 1] + brr[i];
  fac[0] = 1;
  for (int i = 1; i <= 400000; i++)
    fac[i] = (fac[i - 1] * i) % mod;
  facinv[0] = 1;
  for (int i = 1; i <= 400000; i++)
    facinv[i] = (facinv[i - 1] * inv(i)) % mod;
  for (int i = 0; i < k; i++)
  {
    ll temp = nhk(bsum[i], k - i);
    if (i)
      temp = (temp + mod - nhk(bsum[i - 1], k - i)) % mod;
    ans = (ans + temp) % mod;
  }
  cout << ans << endl;
  return 0;
}