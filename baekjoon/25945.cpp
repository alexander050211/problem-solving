#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n;
vector<ll> arr;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());
  ll m = 0;
  for (auto x : arr)
    m += x;
  vector<ll> brr(n);
  ll a = m / n, b = m % n;
  for (int i = 0; i < n - b; i++)
    brr[i] = a;
  for (int i = n - b; i < n; i++)
    brr[i] = a + 1;
  ll ans = 0;
  for (int i = 0; i < n; i++)
    ans += llabs(arr[i] - brr[i]);
  ans /= 2;
  cout << ans << endl;
  return 0;
}