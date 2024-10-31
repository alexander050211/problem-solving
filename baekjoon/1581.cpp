#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (!a && !b)
  {
    cout << d + min(1LL, c) << endl;
    return 0;
  }
  if (!b)
  {
    cout << a << endl;
    return 0;
  }
  if (!c)
  {
    cout << a + 1 + d << endl;
    return 0;
  }
  if (b > c)
    cout << a + d + 2 * min(b, c) + 1 << endl;
  else
    cout << a + d + 2 * min(b, c);
  return 0;
}