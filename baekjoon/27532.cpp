#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll cnt[725][725];
ll arr[1505];
ll n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    ll h, m;
    h = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    arr[i] = (h * 60 + m) % 720;
  }
  for (int i = 1; i <= 720; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      ll temp = (arr[j] - (j - 1) * i) % 720;
      temp = (temp + 720) % 720;
      cnt[i][temp]++;
    }
  }
  ll ans = n;
  for (int i = 1; i <= 720; i++)
  {
    ll temp = 0;
    for (int j = 0; j <= 720; j++)
      if (cnt[i][j])
        temp++;
    ans = min(ans, temp);
  }
  cout << ans << endl;
  return 0;
}