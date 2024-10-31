#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
bool sieve[1000005];
ll psum[1000005];
ll ans[1000005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 2; i <= 1000000; i++)
    sieve[i] = true;
  for (int i = 2; i <= 1000000; i++)
  {
    if (!sieve[i])
      continue;
    for (int j = i * 2; j <= 1000000; j += i)
      sieve[j] = false;
  }
  for (int i = 2; i <= 1000000; i++)
    psum[i] = psum[i - 1] + (sieve[i] == true);
  ans[2] = 1;
  for (int i = 3; i <= 1000000; i++)
    ans[i] = ans[i - 1] + ((sieve[i] == true) && (i % 4 == 1));
  while (1)
  {
    ll a, b;
    cin >> a >> b;
    if (a == -1 && b == -1)
    {
      return 0;
    }
    cout << a << ' ' << b << ' ';
    cout << psum[max(b, 0LL)] - psum[max(a - 1, 0LL)] << ' ';
    cout << ans[max(b, 0LL)] - ans[max(0LL, a - 1)] << endl;
  }
  return 0;
}