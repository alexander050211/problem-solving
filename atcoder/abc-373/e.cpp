#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
ll n, m, k;
vector<pll> arr;
ll ans[200005];
bool g(ll x)
{
}
ll f(ll x)
{
  ll st = 0, en = k;
  while (st < en)
  {
    if (en - st == 1)
    {
    }
    ll mid = (st + en) / 2;
  }
  return st;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i].F;
  for (int i = 0; i < n; i++)
    arr[i].S = i;
  sort(all(arr));
  for (int i = 0; i < n; i++)
    ans[arr[i].S] = f(i);
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  return 0;
}