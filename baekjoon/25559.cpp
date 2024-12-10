#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll n;
  cin >> n;
  if (n == 1)
  {
    cout << 1 << endl;
    return 0;
  }
  if (n % 2)
  {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
  {
    if (i % 2)
      cout << i << ' ';
    else
      cout << n - i << ' ';
  }
  return 0;
}