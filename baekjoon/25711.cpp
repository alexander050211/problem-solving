#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, q;
double arr[200005], brr[200005], crr[200005];
ll x[200005], y[200005];
double dist(ll x1, ll y1, ll x2, ll y2)
{
  return (double)sqrt(pow((double)x2 - x1, 2.0) + pow((double)y2 - y1, 2.0));
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> x[i];
  for (int i = 1; i <= n; i++)
    cin >> y[i];
  for (int i = 2; i <= n; i++)
  {
    arr[i] = arr[i - 1], brr[i] = brr[i - 1], crr[i] = crr[i - 1];
    double temp = dist(x[i - 1], y[i - 1], x[i], y[i]);
    if (y[i - 1] < y[i])
      arr[i] += temp;
    else if (y[i - 1] == y[i])
      brr[i] += temp;
    else
      crr[i] += temp;
  }
  while (q--)
  {
    ll a, b;
    cin >> a >> b;
    double ans = 0;
    if (a < b)
    {
      ans += (arr[b] - arr[a]) * 3.0;
      ans += (brr[b] - brr[a]) * 2.0;
      ans += (crr[b] - crr[a]);
    }
    else
    {
      ans += (crr[a] - crr[b]) * 3.0;
      ans += (brr[a] - brr[b]) * 2.0;
      ans += (arr[a] - arr[b]);
    }
    cout << ans << endl;
  }
  return 0;
}