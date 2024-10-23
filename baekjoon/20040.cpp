#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, m, ans;
ll cp[500005];
ll f(ll x)
{
  if (cp[x] == x)
    return x;
  return cp[x] = f(cp[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cp[i] = i;
  for (int i = 0; i < m; i++)
  {
    ll a, b;
    cin >> a >> b;
    if (f(a) > f(b))
      swap(a, b);
    if (ans)
      continue;
    if (cp[a] == cp[b])
      ans = i + 1;
    else
      cp[cp[b]] = cp[a];
  }
  cout << ans << endl;
  return 0;
}