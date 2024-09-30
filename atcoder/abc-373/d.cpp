#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define INF -(ll)1e15
ll n, m;
ll ans[200005];
vector<pair<pll, ll>> arr;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  arr.resize(m);
  for (int i = 0; i < m; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b)
    {
      swap(a, b);
      c = -c;
    }
    arr[i] = {{a, b}, c};
  }
  sort(all(arr));
  for (int i = 1; i <= n; i++)
    ans[i] = INF;
  for (auto x : arr)
  {
    pll temp = x.F;
    if (ans[temp.F] == INF && ans[temp.S] == INF)
    {
      ans[temp.F] = 0;
      ans[temp.S] = x.S;
    }
    else if (ans[temp.F] == INF)
      ans[temp.F] = ans[temp.S] - x.S;
    else if (ans[temp.S] == INF)
      ans[temp.S] = ans[temp.F] + x.S;
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  return 0;
}