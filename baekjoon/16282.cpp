#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long ll;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.tie(0);
  ll n;
  cin >> n;
  for (ll i = 1; i <= 60; i++)
  {
    ll temp = i + 1;
    temp <<= (i + 1);
    temp--;
    if (n <= temp)
    {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}