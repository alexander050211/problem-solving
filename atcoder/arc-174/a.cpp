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
ll n, k;
vector<ll> arr, sum;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sum.resize(n);
  sum[0] = arr[0];
  for (int i = 1; i < n; i++)
    sum[i] = sum[i - 1] + arr[i];
  ll ans = sum.back();
  if (k >= 1)
  {
    ll res = 0;
    ll t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++)
    {
      t2 += arr[i];
      t1 = min(t1, t2);
      res = max(res, t2 - t1);
    }
    ans += res * (k - 1);
  }
  else
  {
    ll res = 0;
    ll t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++)
    {
      t2 += arr[i];
      t1 = max(t1, t2);
      res = min(res, t2 - t1);
    }
    ans += res * (k - 1);
  }
  cout << ans << endl;
  return 0;
}