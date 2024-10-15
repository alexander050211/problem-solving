#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, b, a;
vector<ll> arr, brr;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> b >> a;
  arr.resize(n);
  brr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());
  brr[0] = arr[0];
  for (int i = 1; i < n; i++)
    brr[i] = brr[i - 1] + arr[i];

  ll sa = 0;
  for (int i = 0; i < a; i++)
    sa += arr[i] / 2;
  if (b < sa)
  {
    ll ans = 0;
    while (ans < a && brr[ans] / 2 <= b)
      ans++;
    cout << ans << endl;
    return 0;
  }
  else
  {
    ll ans = a;
    while (ans < n && brr[ans] / 2 + brr[ans - a] / 2 <= b)
      ans++;
    cout << ans << endl;
    return 0;
  }
  return 0;
}