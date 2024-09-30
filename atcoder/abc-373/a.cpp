#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
#define F first
#define S second
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll cnt = 0;
  for (int i = 0; i < 12; i++)
  {
    string s;
    cin >> s;
    cnt += (s.size() == (i + 1));
  }
  cout << cnt << endl;
  return 0;
}