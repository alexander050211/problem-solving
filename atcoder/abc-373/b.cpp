#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
ll pos[26];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < 26; i++)
    pos[s[i] - 'A'] = i;
  ll ans = 0;
  for (int i = 1; i < 26; i++)
    ans += abs(pos[i] - pos[i - 1]);
  cout << ans << endl;
  return 0;
}