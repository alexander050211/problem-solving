#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (1)
  {
    ll n;
    cin >> n;
    if (!n)
      return 0;
    vector<ll> arr(n, 0);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    ll ans[n][n] = {0};
    if (arr[0] == arr[n - 1])
    {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          ans[i][j] = 0;
      for (int i = 0; i < n; i++)
        ans[n - 1][i] = arr[i];
      for (int i = 0; i < n; i++)
        ans[i][0] = arr[i];
      for (int i = 0; i < n; i++)
        ans[0][n - i - 1] = arr[i];
      for (int i = 0; i < n; i++)
        ans[n - i - 1][n - 1] = arr[i];
      cout << "Yes" << endl;
      for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < n; j++)
          cout << ans[i][j] << " ";
      continue;
    }
    else
    {
      cout << "No" << endl;
      continue;
    }
  }
  return 0;
}