#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long ll;
#define all(x) x.begin(), x.end()
#define F first
#define S second
typedef pair<ll, ll> pll;
#define mod 998244353
#define INF (ll)1e15
#define pb emplace_back
#define mp make_pair
vector<pll> arr;
ll f(ll n)
{
  ll ans = 0;
  for (auto x : arr)
  {
    if (n < x.F)
      continue;
    ans += min(x.S, n) - x.F + 1;
  }
  return ans;
}
ll ppow(ll a, ll b)
{
  ll ret = 1;
  ll aa = a;
  while (b)
  {
    if (b % 2)
      ret *= aa;
    aa *= aa;
    b /= 2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  arr.pb(mp(1, 1));
  for (int i = 1; i <= 9; i++)
  {
    arr.pb(mp(ppow(10, 2 * i) - ppow(10, i), ppow(10, 2 * i) + ppow(10, i) - 1));
    arr.pb(mp(ppow(10, 2 * i) - 2 * ppow(10, i), ppow(10, 2 * i) - 2 * ppow(10, i)));
  }
  ll t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    cout << f(n) << endl;
  }
  return 0;
}