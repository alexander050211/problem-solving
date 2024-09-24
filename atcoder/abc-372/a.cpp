#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  ll len = s.size();
  for (int i = 0; i < len; i++)
    if (s[i] != '.')
      cout << s[i];
  return 0;
}