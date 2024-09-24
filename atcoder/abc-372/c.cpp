#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
ll n, q;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  cin >> s;
  ll cnt = 0;
  for (int i = 2; i < n; i++)
  {
    if (s[i] == 'C' && s[i - 1] == 'B' && s[i - 2] == 'A')
      cnt++;
  }
  while (q--)
  {
    ll x;
    char c;
    cin >> x >> c;
    x--;
    if (s[x] == c)
    {
      cout << cnt << endl;
      continue;
    }
    if (s[x] == 'A' && (x + 1 < n && s[x + 1] == 'B') && (x + 2 < n && s[x + 2] == 'C'))
    {
      if (c != 'A')
        cnt--;
    }
    else if (s[x] == 'B' && (x - 1 >= 0 && s[x - 1] == 'A') && (x + 1 < n && s[x + 1] == 'C'))
    {
      if (c != 'B')
        cnt--;
    }
    else if (s[x] == 'C' && (x - 1 >= 0 && s[x - 1] == 'B') && (x - 2 >= 0 && s[x - 2] == 'A'))
    {
      if (c != 'C')
        cnt--;
    }

    if (c == 'A' && (x + 1 < n && s[x + 1] == 'B') && (x + 2 < n && s[x + 2] == 'C'))
      cnt++;
    if (c == 'B' && (x - 1 >= 0 && s[x - 1] == 'A') && (x + 1 < n && s[x + 1] == 'C'))
      cnt++;
    if (c == 'C' && (x - 1 >= 0 && s[x - 1] == 'B') && (x - 2 >= 0 && s[x - 2] == 'A'))
      cnt++;
    s[x] = c;
    cout << cnt << endl;
  }
  return 0;
}