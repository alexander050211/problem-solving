#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
void solve()
{
  ll n;
  string s;
  cin >> n >> s;
  ll ans = 0;
  vector<ll> arr = vector<ll>();
  for (int i = 0; i < n; i++)
    if (s[i] == '1')
      arr.push_back(i);
  if (arr.size() % 2)
  {
    cout << -1 << endl;
    return;
  }
  if (arr.size() == 2)
  {
    if (arr[1] - arr[0] > 1)
      ans = 1;
    else
    {
      ans = 2;
      if (n == 4 && arr[0] == 1 && arr[1] == 2)
        ans = 3;
      else if (n < 4)
        ans = -1;
      else if (arr[0] == 0 || arr.back() == n - 1)
        ans = 2;
    }
  }
  else
    ans = arr.size() / 2;
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