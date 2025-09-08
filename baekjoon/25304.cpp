#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll x, n;
  cin >> x >> n;
  ll temp = 0;
  for (int i = 1; i <= n; i++)
  {
    ll a, b;
    cin >> a >> b;
    temp += a * b;
  }
  if (x == temp)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}