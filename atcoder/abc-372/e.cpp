#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
ll n, q;
ll parent[200005];
ll arr[200005][15];
ll v(ll x)
{
  if (x == parent[x])
    return x;
  return parent[x] = v(parent[x]);
}
void g(ll a, ll b)
{
  vector<ll> temp = vector<ll>();
  ll ta = v(a);
  ll tb = v(b);
  for (int i = 0; i < 10; i++)
  {
    temp.push_back(arr[ta][i]);
    temp.push_back(arr[tb][i]);
  }
  sort(all(temp));
  reverse(all(temp));
  ll t = max(ta, tb);
  parent[min(ta, tb)] = max(ta, tb);
  for (int i = 0; i < 10; i++)
    arr[t][i] = temp[i];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i;
    arr[i][0] = i;
  }
  while (q--)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1)
    {
      if (v(b) == v(c))
        continue;
      g(b, c);
    }
    else
    {
      ll x = v(b);
      if (!arr[x][c - 1])
        cout << -1 << endl;
      else
        cout << arr[x][c - 1] << endl;
    }
  }
  return 0;
}