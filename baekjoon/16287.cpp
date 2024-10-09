#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll arr[5005], t1[400005], t2[400005];
ll n, k;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> k >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i <= 400000; i++)
    t1[i] = t2[i] = -1;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
    {
      ll temp = arr[i] + arr[j];
      if (t1[temp] == -1)
      {
        t1[temp] = i;
        t2[temp] = j;
      }
    }

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
    {
      ll temp = k - arr[i] - arr[j];
      if (temp < 0 || temp > 400000 || t1[temp] == -1)
        continue;
      if (t1[temp] != i && t1[temp] != j && t2[temp] != i && t2[temp] != j)
      {
        cout << "YES" << endl;
        return 0;
      }
    }
  cout << "NO" << endl;
  return 0;
}