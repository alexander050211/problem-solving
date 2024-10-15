#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll arr[10005];
ll n, sum1, sum2;
ll brr[7] = {100, 50, 20, 10, 5, 2, 1};
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  sum1 = arr[1];
  sum2 = arr[2];
  for (int i = 3; i <= n; i++)
  {
    if (sum1 > sum2)
      sum2 += arr[i];
    else
      sum1 += arr[i];
  }
  ll m = llabs(sum1 - sum2);
  ll ans = 0;
  for (int i = 0; i < 7; i++)
  {
    ans += m / brr[i];
    m %= brr[i];
  }
  cout << ans << endl;
  return 0;
}