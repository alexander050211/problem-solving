#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n;
string str;
ll cnt[100005];
ll b[100005];
vector<ll> arr[100005];
vector<ll> inv[100005];
bool f(ll x)
{
  ll idx = lower_bound(arr[x].begin(), arr[x].end(), x) - arr[x].begin();
  return arr[x][idx] == x;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  getline(cin, str);
  // cin.ignore();
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    ll m;
    cin >> m;
    arr[i].resize(m);
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++)
  {
    for (auto x : arr[i])
    {
      if (b[i])
        cnt[x]++;
      else
        cnt[x]--;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (auto x : arr[i])
      inv[x].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    sort(inv[i].begin(), inv[i].end());
  ll val = -n;
  for (int i = 1; i <= n; i++)
    val = max(val, cnt[i]);

  bool check = false;
  for (int i = 1; i <= n; i++)
  {
    if (cnt[i] < val - 1)
      continue;
    if (cnt[i] == val - 1)
    {
    }
    if (f(i) != b[i])
    {
      check = true;
      cout << i << ' ';
    }
  }
  if (!check)
    cout << "swi" << endl;
  return 0;
}