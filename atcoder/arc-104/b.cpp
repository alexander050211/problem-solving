#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll sum1[5005], sum2[5005];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
  {
    sum1[i + 1] = sum1[i];
    sum2[i + 1] = sum2[i];
    if (s[i] == 'A')
      sum1[i + 1]++;
    else if (s[i] == 'T')
      sum1[i + 1]--;
    else if (s[i] == 'C')
      sum2[i + 1]++;
    else if (s[i] == 'G')
      sum2[i + 1]--;
  }
  ll ans = 0;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++)
    {
      if (sum1[j] == sum1[i - 1] && sum2[j] == sum2[i - 1])
        ans++;
    }
  cout << ans << endl;
  return 0;
}