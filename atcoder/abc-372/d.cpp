#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
ll ans[200005];
ll st[200005];
ll idx;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin >> n;
  vector<ll> arr(n + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  for (int i = n; i > 0; i--)
  {
    while (idx && st[idx - 1] < arr[i])
      idx--;
    st[idx++] = arr[i];
    ans[i - 1] = idx;
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  return 0;
}