#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define check cout << "*" << endl
ll n;
ll arr[15];
vector<ll> temp;
ll ans;
ll q;
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
  return ppow(a, mod - 2);
}
ll f()
{
  vector<ll> dp(n, 1);
  ll ret = 1;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
      if (temp[i] > temp[j])
        dp[i] = max(dp[i], dp[j] + 1);
    ret = max(ret, dp[i]);
  }
  return ret;
}
ll nck(ll a, ll b)
{
  if (!b)
    return 1;
  if (a < b)
    return 0;
  if (a == b)
    return 1;
  ll ret = 1;
  for (int i = 0; i < b; i++)
    ret = (ret * (a - i)) % mod;
  for (int i = 2; i <= b; i++)
    ret = (ret * inv(i)) % mod;
  return ret % mod;
}
void dfs(ll x)
{
  if (x == n)
  {
    ll mm = 0;
    for (auto x : temp)
      mm = max(mm, x);
    vector<bool> cc(mm + 1, false);
    for (auto x : temp)
      cc[x] = true;
    for (int i = 1; i <= mm; i++)
      if (!cc[i])
        return;

    ll len = f();
    vector<ll> brr(n, mod);
    for (int i = 0; i < n; i++)
      brr[temp[i] - 1] = min(brr[temp[i] - 1], arr[i]);
    ll idx = n - 1;
    while (idx > 0 && brr[idx] == mod)
      idx--;
    for (int i = idx - 1; i >= 0; i--)
      brr[i] = min(brr[i], brr[i + 1] - 1);
    ll cnt = idx + 1;

    vector<ll> crr(cnt, 0);

    for (int i = 0; i < cnt; i++)
    {
      crr[i] = nck(brr[i], i + 1);

      for (int j = 0; j < i; j++)
      {
        ll t = 1;
        if (j)
          t = crr[j - 1];

        t = (t * nck(brr[i] - brr[j], i + 1 - j)) % mod;
        crr[i] = (crr[i] - t + mod) % mod;
      }
    }

    ll ret = crr[cnt - 1];
    ans = (ans + ret * len) % mod;
    q = (q + ret) % mod;
    return;
  }
  for (int i = 1; i <= n; i++)
  {
    temp.emplace_back(i);
    dfs(x + 1);
    temp.pop_back();
  }
}
int main()
{
  // ios_base::sync_with_stdio(0);
  //  cin.tie(0);
  //  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  dfs(0);
  ans = (ans * inv(q)) % mod;
  cout << ans << endl;
  return 0;
}