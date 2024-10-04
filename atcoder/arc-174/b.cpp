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
ll arr[6], brr[6];
void solve()
{
  for (int i = 1; i <= 5; i++)
    cin >> arr[i];
  for (int i = 1; i <= 5; i++)
    cin >> brr[i];
  ll ans = 0;
  ll n = 2 * (arr[1] - arr[5]) + (arr[2] - arr[4]);
  if (n <= 0)
  {
    cout << 0 << endl;
    return;
  }
  ll t1 = brr[4], t2 = brr[5];
  if (2 * t1 < t2)
    ans = n * t1;
  else
  {
    ans += (n / 2) * t2;
    if (n % 2)
      ans += min(t1, t2);
  }
  cout << ans << endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}