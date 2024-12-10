#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--)
  {
    ll n, st, en;
    cin >> n >> st >> en;
    if (st == 1 && en == n)
      cout << 0 << endl;
    else if (st == n && en == 1)
      cout << 0 << endl;
    else if (st == 1)
      cout << 1 << endl;
    else if (st == n)
      cout << 1 << endl;
    else if (en - st == 1 || en - st == -1)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
  return 0;
}